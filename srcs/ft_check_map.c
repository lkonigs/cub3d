/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkconditions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonig <lkonig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:05:23 by lkonig            #+#    #+#             */
/*   Updated: 2021/01/20 15:32:48 by lkonig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		check_finalmap(t_param *param, int i, int j)
{
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