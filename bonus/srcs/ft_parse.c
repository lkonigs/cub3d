/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonig <lkonig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:08:59 by lkonig            #+#    #+#             */
/*   Updated: 2021/01/20 15:41:00 by lkonig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		set_dirvect(t_param *param)
{
	if ((param->player.angle == 180))
	{
		param->player.dir.x = -1;
		param->plane.vect.y = tan(30) / 10;
	}
	else if ((param->player.angle == 0))
	{
		param->player.dir.x = 1;
		param->plane.vect.y = -tan(30) / 10;
	}
	else if (param->player.angle == 270)
	{
		param->player.dir.y = 1;
		param->plane.vect.x = tan(30) / 10;
	}
	else
	{
		param->player.dir.y = -1;
		param->plane.vect.x = -tan(30) / 10;
	}
}

void		parse_check(t_param *param)
{
	int		i;

	if (param->startmap == -1)
		error(6, param);
	if (param->player.nb != 1)
		error(7, param);
	if (param->res.x == -1 || param->res.y == -1)
		error(3, param);
	if (!param->no_ptr || !param->so_ptr || !param->ea_ptr
		|| !param->we_ptr || !param->sp_ptr)
		error(2, param);
	if (param->player.pos.x == -1 || param->player.pos.y == -1 ||
		param->player.angle == -1)
		error(10, param);
	i = 0;
	while (i < 3)
	{
		if (param->fcol[i] > 255 || param->fcol[i] < 0 ||
				param->ccol[i] > 255 || param->ccol[i] < 0)
			error(5, param);
		i++;
	}
	if (param->nbparam != 8)
		error(4, param);
}

int			parse_aftermap(t_param *param, char *line, int i)
{
	if (param->endmap == -1 && line[i] == '1')
	{
		if (parse_map(line, param) != 0)
			return (8);
	}
	else if (param->endmap == -1 && line[i] == ' ')
	{
		if (parse_map(line, param) != 0)
			return (8);
	}
	else if (param->endmap == -1 && param->startmap == 1)
		return (8);
	return (0);
}

int			parse_beforemap(t_param *param, char *line, int i)
{
	if (param->startmap == -1)
	{
		if ((line[i] == 'R') && line[i + 1] == ' ')
		{
			if (parse_res(line, param) == -1)
				return (3);
		}
		else if ((line[i] == 'F' || line[i] == 'C') && line[i + 1] == ' ')
		{
			if (parse_col(line + i, param) == -1)
				return (2);
		}
		else if ((((line[i] == 'N' && line[i + 1] == 'O')
			|| (line[i] == 'S' && line[i + 1] == 'O') || (line[i] == 'W'
			&& line[i + 1] == 'E') || (line[i] == 'E'
			&& line[i + 1] == 'A')) && (line[i + 2] == ' '))
			|| (line[i] == 'S' && line[i + 1] == ' '))
		{
			if (parse_text(line, param) == -1)
				return (7);
		}
		else if (line[i] != '1' && line[i] != ' ' && *line)
			return (4);
	}
	return (parse_aftermap(param, line, i));
}

int			parse_configline(char *line, t_param *param)
{
	int		i;

	i = 0;
	if (param->endmap == 1 && !(*line))
	{
		param->endfile = 1;
		return (0);
	}
	else if (param->endmap == 1 && param->endfile == -1
		&& (line[i] == '1' || line[i] == ' '))
	{
		if (check_wall(line, i) == 1)
			return (5);
	}
	else if (param->endmap == 1 && line[i] == ' ' && param->endfile == 1)
		return (1);
	else if (param->endmap == 1 && param->endfile == 1)
		return (1);
	while (line[i] == ' ')
		i++;
	return (parse_beforemap(param, line, i));
}
