/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite_sort_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonig <lkonig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:15:23 by lkonig            #+#    #+#             */
/*   Updated: 2021/01/20 15:46:54 by lkonig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void				sort_sprite(t_param *param)
{
	unsigned int	n;
	unsigned int	k;

	n = -1;
	while (++n < param->nb_sprite)
	{
		k = n - 1;
		while (++k < param->nb_sprite)
		{
			if (param->sprites[k].dist < param->sprites[n].dist)
				ft_switch(param, k, n);
		}
	}
	k = 0;
	while (k < param->nb_sprite)
		k++;
}

void				ft_switch(t_param *param, int k, int n)
{
	int				tmpx;
	int				tmpy;
	double			tmpdist;

	tmpx = param->sprites[n].pos.x;
	tmpy = param->sprites[n].pos.y;
	tmpdist = param->sprites[n].dist;
	param->sprites[n].pos.x = param->sprites[k].pos.x;
	param->sprites[n].pos.y = param->sprites[k].pos.y;
	param->sprites[n].dist = param->sprites[k].dist;
	param->sprites[k].pos.x = tmpx;
	param->sprites[k].pos.y = tmpy;
	param->sprites[k].dist = tmpdist;
}
