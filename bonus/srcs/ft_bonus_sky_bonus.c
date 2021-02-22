/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus_sky_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonig <lkonig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 15:19:22 by lkonig            #+#    #+#             */
/*   Updated: 2021/02/15 17:05:21 by lkonig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

char				*sky_texture_set(t_param *param)
{
	char			*text;
	int				u;

	text = NULL;
	text = mlx_get_data_addr(param->sky_ptr, &u, &u, &u);
	return (text);
}

t_floor				sky_set(t_param *param, t_floor floor, double dist)
{
	floor.step.x = dist * (2 * param->plane.vect.x) / param->res.x;
	floor.step.y = dist * (2 * param->plane.vect.y) / param->res.x;
	floor.f.x = param->player.pos.x - dist * (param->player.dir.x
		- param->plane.vect.x);
	floor.f.y = param->player.pos.y - dist * (param->player.dir.y
		- param->plane.vect.y);
	return (floor);
}

t_floor				sky_update(t_floor floor)
{
	floor.t.x = (int)(WH * (floor.f.x - (int)floor.f.x)) & (WH - 1);
	floor.t.y = (int)(WH * (floor.f.y - (int)floor.f.y)) & (WH - 1);
	floor.f.x += floor.step.x;
	floor.f.y += floor.step.y;
	return (floor);
}

void				sky_texture(t_param *param)
{
	t_multiint		pos;
	t_multiint		i;
	double			dist;
	char			*text;
	t_floor			sky;

	sky = floor_init();
	i.x = param->res.x * param->res.y * 2;
	pos.y = param->res.y / 2 - 1;
	text = sky_texture_set(param);
	while (pos.y >= 0 && i.x >= 0)
	{
		dist = (0.5 * param->res.y) / (int)(pos.y-- - param->res.y / 2);
		sky = sky_set(param, sky, dist);
		pos.x = param->res.x;
		i.y = 0;
		while (--pos.x >= 0)
		{
			sky = sky_update(sky);
			i.y = (WH * sky.t.y + sky.t.x) * 4;
			floor_apply(param, i, text, dist);
			i.x -= 4;
		}
	}
}
