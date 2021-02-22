/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonig <lkonig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:05:23 by lkonig            #+#    #+#             */
/*   Updated: 2021/01/20 15:32:48 by lkonig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int		check_empty(t_param *param, int i, int j)
{
	if (!param->tempmap[i][j + 1] ||
		!param->tempmap[i + 1][j] ||
		(!param->tempmap[i + 1][j + 1] &&
		(param->tempmap[i + 1][j] != '1' ||
		param->tempmap[i][j + 1] != '1')) ||
		(!param->tempmap[i + 1][j - 1] &&
		(param->tempmap[i + 1][j] != '1' ||
		param->tempmap[i][j - 1] != '1')) ||
		!param->tempmap[i - 1][j] ||
		!param->tempmap[i][j - 1] ||
		(!param->tempmap[i - 1][j - 1] &&
		(param->tempmap[i - 1][j] != '1' ||
		param->tempmap[i][j - 1] != '1')) ||
		(!param->tempmap[i - 1][j + 1] &&
		(param->tempmap[i][j + 1] != '1' ||
		param->tempmap[i - 1][j] != '1')))
		return (1);
	return (0);
}

int		check_finalmap(t_param *param, int i, int j)
{
	if (check_empty(param, i, j) == 1)
		return (1);
	if (param->tempmap[i][j + 1] == ' ' ||
		param->tempmap[i + 1][j] == ' ' ||
		(param->tempmap[i + 1][j + 1] == ' ' &&
		(param->tempmap[i + 1][j] != '1' ||
		param->tempmap[i][j + 1] != '1')) ||
		(param->tempmap[i + 1][j - 1] == ' ' &&
		(param->tempmap[i + 1][j] != '1' ||
		param->tempmap[i][j - 1] != '1')) ||
		param->tempmap[i - 1][j] == ' ' ||
		param->tempmap[i][j - 1] == ' ' ||
		(param->tempmap[i - 1][j - 1] == ' ' &&
		(param->tempmap[i - 1][j] != '1' ||
		param->tempmap[i][j - 1] != '1')) ||
		(param->tempmap[i - 1][j + 1] == ' ' &&
		(param->tempmap[i][j + 1] != '1' ||
		param->tempmap[i - 1][j] != '1')))
		return (1);
	return (0);
}

int		check_map(t_param *param, int i, int j, int type)
{
	if (param->tempmap[i][j] == '2' || param->tempmap[i][j] == '0'
		|| param->tempmap[i][j] >= 'A')
	{
		if (i == 0 || j == 0)
		{
			if (type == 0)
				return (8);
			error(8, param);
		}
		if (type == 0)
		{
			if (param->tempmap[i - 1][j] == ' ' ||
				param->tempmap[i][j - 1] == ' ')
				return (8);
		}
		else
		{
			if (i == param->mapsize.y - 1 ||
				j == ft_strlen(param->tempmap[i]) - 1 ||
				check_finalmap(param, i, j))
				error(8, param);
		}
	}
	return (0);
}

int		check_wall(char *line, int i)
{
	int j;
	int	wall;

	j = i;
	wall = 0;
	while (line[j])
	{
		if (line[j] == '1')
			wall = 1;
		if (line[j] != '1' && line[j] != ' ')
			return (1);
		j++;
	}
	if (wall == 0)
		return (1);
	return (0);
}

void	check_init(t_param *param)
{
	param->endmap = 1;
	if (param->startmap == -1)
	{
		param->startmap = 1;
		param->endmap = -1;
	}
}
