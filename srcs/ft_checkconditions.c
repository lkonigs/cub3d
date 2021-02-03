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

int		check_map(t_param *param, int i, int j, int type)
{
	if (param->tempmap[i][j] == '2' || param->tempmap[i][j] == '0'
		|| param->tempmap[i][j] >= 'A')
	{
		if (i == 0 || j == 0)
		{
			if (type == 0)
				return (8);
			else
				error(8, param);
		}
		if (type == 0)
		{
			if (param->tempmap[i - 1][j - 1] == ' ' ||
				param->tempmap[i - 1][j] == ' ' ||
				param->tempmap[i][j - 1] == ' ' ||
				param->tempmap[i - 1][j + 1] == ' ')
				return (8);
		}
		else
		{
			if (i == param->mapsize.y - 1 ||
				j == ft_strlen(param->tempmap[i]) - 1 ||
				param->tempmap[i + 1][j - 1] == ' ' ||
				param->tempmap[i][j + 1] == ' ' ||
				param->tempmap[i + 1][j] == ' ' ||
				param->tempmap[i + 1][j + 1] == ' ')
				error(8, param);
		}
	}
	return (0);
}

int		check_sp(t_param *param, int i, int j, unsigned int k)
{
	unsigned int	n;

	n = 0;
	while (n < k)
	{
		if (((i >= param->sprites[n].pos.x - 32 &&
			i < param->sprites[n].pos.x + 32)
			&& (j > param->sprites[n].pos.y - 32 &&
			(j - param->sprites[n].pos.y) < 32))
			|| ((j >= param->sprites[n].pos.y - 32 &&
			j < param->sprites[n].pos.y + 32)
			&& (i > param->sprites[n].pos.x - 32 &&
			(i - param->sprites[n].pos.x) < 32)))
			return (0);
		n++;
	}
	return (1);
}

int		check_inter_sp(t_point b, t_param *param, unsigned int k)
{
	if (((int)b.pos.y >= param->sprites[k].pos.y - 32) &&
		((int)b.pos.y < param->sprites[k].pos.y + 32) &&
		(((int)b.pos.x >= param->sprites[k].pos.x - 32) &&
		((int)b.pos.x < param->sprites[k].pos.x + 32)))
		return (1);
	return (0);
}

int		check_proximity_x(int max_pos, int gv_pos, t_param *param)
{
	if ((param->map[gv_pos][max_pos] != '1') &&
			(param->map[gv_pos][max_pos] != '2'))
	{
		if (param->player.pos.x < max_pos && (param->map[gv_pos][max_pos + PR] != '1') &&
			(param->map[gv_pos][max_pos + PR] != '2'))
			return (1);
		if (param->player.pos.x > max_pos && (param->map[gv_pos][max_pos - PR] != '1') &&
			(param->map[gv_pos][max_pos - PR] != '2'))
			return (1);
	}
	return (0);
}

int		check_proximity_y(int max_pos, int gv_pos, t_param *param)
{
	if ((param->map[max_pos][gv_pos] != '1') &&
			(param->map[max_pos][gv_pos] != '2'))
	{
		if (param->player.pos.y < max_pos && (param->map[max_pos + PR][gv_pos] != '1') &&
			(param->map[max_pos + PR][gv_pos] != '2'))
			return (1);
		if (param->player.pos.y > max_pos && ((param->map[max_pos - PR][gv_pos] != '1') &&
			(param->map[max_pos - PR][gv_pos] != '2')))
			return (1);
	}
	return (0);
}
