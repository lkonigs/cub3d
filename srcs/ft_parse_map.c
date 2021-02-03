/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonig <lkonig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:10:24 by lkonig            #+#    #+#             */
/*   Updated: 2021/01/20 15:41:42 by lkonig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		fill_map(t_param *param, int i, int j)
{
	if (param->tempmap[j / 64][i / 64] <= '2')
		param->map[j][i] = param->tempmap[j / 64][i / 64];
	else if (param->player.pos.x == -1)
	{
		init_player(param, param->tempmap[j / 64][i / 64], i, j);
		param->map[j][i] = '0';
	}
	else
	{
		param->map[j][i] = '0';
	}
	check_map(param, j / 64, i / 64, 1);
	if (param->map[j][i] == ' ')
		param->map[j][i] = '1';
}

int			get_finalmap(t_param *param)
{
	int		i;
	int		j;
	int		k;
	int		len;

	j = 0;
	len = 0;
//	param->map = NULL;
	if (!(param->map = malloc(sizeof(char *) * 64 * param->mapsize.y)))
		error(1, param);
	k = 0;
	while (k < 64 * param->mapsize.y)
		param->map[k++] = NULL;
//	param->map[j] = NULL;
	while (j < param->mapsize.y * 64)
	{
		i = 0;
		len = ft_strlen(param->tempmap[j / 64]);
		if (!(param->map[j] = malloc(sizeof(char) * 64 * len + 1)))
			error(1, param);
		param->map[j][0] = 0;
		while (i < 64 * len)
		{
			fill_map(param, i, j);
			i++;
		}
		param->map[j][i] = 0;
		j++;
	}
	return (0);
}

int			apply_line(int i, int j, t_param *param, char *line)
{
	int		k;
	int		res;

	k = -1;
	res = 0;
	param->endmap = 1;
	if (param->startmap == -1)
	{
		param->startmap = 1;
		param->endmap = -1;
	}
	while (line[++k])
	{
		param->tempmap[i][++j] = line[k];
		if (line[k] != '1' && line[k] != ' ')
			param->endmap = -1;
		if (line[k] == '0' || line[k] >= 'A')
			res = check_map(param, i, j, 0);
	}
	param->tempmap[i++][++j] = 0;
	return (res);
}

int			parse_map(char *line, t_param *param)
{
	int		j;
	int		i;
	int		res;

	j = -1;
	res = 0;
	i = param->mapsize.y;
	if (!(param->tempmap[i] = malloc(sizeof(char) * (ft_strlen(line) + 1))))
		return (9);
	param->tempmap[i][0] = 0;
	while (line[++j])
	{
		if (line[j] != '0' && line[j] != '1' && line[j] != '2'
			&& line[j] != 'N' && line[j] != 'S' && line[j] != 'E'
			&& line[j] != 'W' && line[j] != ' ')
			return (-1);
		if (line[j] == 'N' || line[j] == 'S' || line[j] == 'E'
			|| line[j] == 'W')
			param->player.nb++;
	}
	j = -1;
	res = apply_line(i, j, param, line);
	param->mapsize.y++;
	return (res);
}
