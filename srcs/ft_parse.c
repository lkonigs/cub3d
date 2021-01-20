/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonig <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:08:59 by lkonig            #+#    #+#             */
/*   Updated: 2020/10/27 15:09:57 by lkonig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

#include <stdio.h>//

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
}

void		parse_free(char *line, t_param *param)
{
	parse_configline(line, param);
	ft_free(line);
}

void		parse_configfile(int fd, t_param *param)
{
	char	*line;
	int		res;

	res = 0;
	while ((res = get_next_line(fd, &line)) > 0)
		parse_free(line, param);
	if (*line)
		parse_free(line, param);
	nb_sprite(param);
	get_finalmap(param);
	ft_sprite(param);
	parse_check(param);
	set_dirvect(param);
}

void		parse_configline(char *line, t_param *param)
{
	int		i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == 'R' && parse_res(line + i, param) == -1)
		error(2, param);
	else if (line[i] == 'F' || line[i] == 'C')
		parse_col(line + i, param);
	else if (((line[i] == 'N' && line[i + 1] == 'O')
				|| (line[i] == 'S' && line[i + 1] == 'O')
				|| (line[i] == 'W' && line[i + 1] == 'E')
				|| (line[i] == 'E' && line[i + 1] == 'A')
				|| (line[i] == 'S' && line[i + 1] == ' '))
				&& parse_text(line, param) == -1)
		error(7, param);
	else if (line[i] == '1' && parse_map(line, param) == -1)
		error(8, param);
}
