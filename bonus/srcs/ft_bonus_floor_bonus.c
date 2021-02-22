/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus_floor_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonig <lkonig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 15:19:22 by lkonig            #+#    #+#             */
/*   Updated: 2021/02/15 17:05:21 by lkonig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

char				*floor_texture_set(t_param *param)
{
	char			*text;
	int				u;

	text = NULL;
	text = mlx_get_data_addr(param->fl_ptr, &u, &u, &u);
	return (text);
}

t_floor				floor_init(void)
{
	t_floor			floor;

	floor.step.x = 0;
	floor.step.y = 0;
	floor.f.x = 0;
	floor.f.y = 0;
	return (floor);
}

t_floor				floor_set(t_param *param, t_floor floor, double dist)
{
	floor.step.x = dist * (2 * param->plane.vect.x) / param->res.x;
	floor.step.y = dist * (2 * param->plane.vect.y) / param->res.x;
	floor.f.x = (double)param->player.pos.x / 100 + dist * (param->player.dir.x
		- param->plane.vect.x);
	floor.f.y = (double)param->player.pos.y / 100 + dist * (param->player.dir.y
		- param->plane.vect.y);
	return (floor);
}

t_floor				floor_update(t_floor floor)
{
	floor.t.x = (int)(WH * fabs(floor.f.x - (int)floor.f.x)) & (WH - 1);
	floor.t.y = (int)(WH * fabs(floor.f.y - (int)floor.f.y)) & (WH - 1);
	floor.f.x += floor.step.x;
	floor.f.y += floor.step.y;
	return (floor);
}

void				floor_texture(t_param *param)
{
	t_multiint		pos;
	t_multiint		i;
	double			dist;
	char			*text;
	t_floor			floor;

	floor = floor_init();
	i.x = param->res.x * param->res.y * 2;
	pos.y = param->res.y / 2;
	text = floor_texture_set(param);
	while (pos.y < param->res.y && i.x < param->res.x * param->res.y * 4)
	{
		dist = (0.5 * param->res.y) / (int)(pos.y++ - param->res.y / 2);
		floor = floor_set(param, floor, dist);
		pos.x = 0;
		i.y = 0;
		while (pos.x++ < param->res.x)
		{
			floor = floor_update(floor);
			i.y = (WH * floor.t.y + floor.t.x) * 4;
			floor_apply(param, i, text, dist);
			i.x += 4;
		}
	}
}
