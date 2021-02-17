/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersection_tools.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonig <lkonig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:10:24 by lkonig            #+#    #+#             */
/*   Updated: 2021/01/20 15:40:34 by lkonig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double			set_angle(double angle)
{
	while (angle < 0)
		angle += 360;
	while (angle >= 360)
		angle -= 360;
	return (angle);
}

double			set_tan(double angle)
{
	double		tan_angle;

	tan_angle = 0;
	if (angle < 90)
		tan_angle = tan(angle * M_PI / 180);
	else if (angle < 180)
		tan_angle = tan(-(180.0 - angle) * M_PI / 180);
	else if (angle < 270)
		tan_angle = tan((180.0 + angle) * M_PI / 180);
	else
		tan_angle = tan(-(360.0 - angle) * M_PI / 180);
	return (tan_angle);
}

t_point			update_pointv(t_point b, double angle, double tan_angle)
{
	if (angle >= 90 && angle < 270)
	{
		b.pos.x -= 64;
		b.pos.y += 64 * tan_angle;
	}
	else
	{
		b.pos.x += 64;
		b.pos.y -= 64 * tan_angle;
	}
	return (b);
}

t_point			update_pointh(t_point a, double angle, double tan_angle)
{
	if (angle < 180)
	{
		a.pos.y -= 64;
		a.pos.x += 64 / tan_angle;
	}
	else
	{
		a.pos.y += 64;
		a.pos.x -= 64 / tan_angle;
	}
	return (a);
}

double			update_dist(t_point a, t_param *param)
{
	double		dist;

	dist = pow(param->player.pos.x - a.pos.x, 2) +
		pow(param->player.pos.y - a.pos.y, 2);
	return (dist);
}
