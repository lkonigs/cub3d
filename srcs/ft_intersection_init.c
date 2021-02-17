/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersection_init.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonig <lkonig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:05:23 by lkonig            #+#    #+#             */
/*   Updated: 2021/01/20 15:40:13 by lkonig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_point	init_ptv(double angle, t_point b, t_param *p, double tan)
{
	if (angle >= 90 && angle < 270)
		b.pos.x = p->player.pos.x / 64 * 64 - 0.000000000001;
	else
		b.pos.x = p->player.pos.x / 64 * 64 + 64;
	b.pos.y = p->player.pos.y + (p->player.pos.x - b.pos.x) * tan;
	return (b);
}

t_point	init_pth(double angle, t_point a, t_param *p, double tan)
{
	if (angle < 180)
		a.pos.y = p->player.pos.y / 64 * 64 - 0.000000000001;
	else
		a.pos.y = p->player.pos.y / 64 * 64 + 64;
	a.pos.x = p->player.pos.x + (p->player.pos.y - a.pos.y) / tan;
	return (a);
}
