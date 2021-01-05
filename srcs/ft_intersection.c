/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonig <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 14:55:24 by lkonig            #+#    #+#             */
/*   Updated: 2020/10/27 14:55:29 by lkonig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_point			intersection(t_param *param, int col, double angle)
{
	double		tan_angle;
	t_point		a;
	t_point		b;

	angle = set_angle(angle);
	tan_angle = set_tan(angle);
	b = inter_v(param, angle, tan_angle, col);
	a = inter_h(param, angle, tan_angle, b);
	a = inter_cmp(a, b, param, angle);
	return (a);
}

t_point			inter_v(t_param *param, double angle, double t_ang, int c)
{
	t_point		b;

	b.col = c;
	b = init_ptv(angle, b, param, t_ang);
	while (b.pos.y > 0 && b.pos.y < param->mapsize.y * 64 &&
		param->map[(int)b.pos.y][(int)b.pos.x] != '1')
		b = update_pointv(b, angle, t_ang);
	b.dist = update_dist(b, param);
	if (b.pos.y < 0 || b.pos.y > param->mapsize.y * 64)
		b.dist = -1;
	if (angle >= 90 && angle < 270)
		b.text = 'E';
	else
		b.text = 'W';
	return (b);
}

t_point			inter_h(t_param *pr, double ang, double tan, t_point b)
{
	t_point		a;

	a.col = b.col;
	a = init_pth(ang, a, pr, tan);
	if (!pr->map[(int)a.pos.y])
		pr->map[(int)a.pos.y] = NULL;
	while (a.pos.x > 0 && a.pos.x < ft_strlen(pr->map[(int)a.pos.y]) &&
		pr->map[(int)a.pos.y][(int)a.pos.x] != '1')
		a = update_pointh(a, ang, tan);
	a.dist = update_dist(a, pr);
	if (a.pos.x < 0 || a.pos.x >= ft_strlen(pr->map[(int)a.pos.y]))
		a.dist = b.dist + 1;
	if (a.dist < b.dist || b.dist == -1)
	{
		if (ang < 180)
			a.text = 'S';
		else
			a.text = 'N';
		return (a);
	}
	return (b);
}

t_point			inter_cmp(t_point a, t_point b, t_param *p, double angle)
{
	t_point		t;

	if (((a.dist > b.dist) || (a.dist == -1)) && b.dist > -1)
		t = b;
	else if (((b.dist > a.dist) || (b.dist == -1) ||
		(b.dist == a.dist)) && a.dist > -1)
		t = a;
	else
		error(12, p);
	t.dist = sqrt(t.dist) * cos((angle - p->player.angle) * M_PI / 180);
	return (t);
}
