/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersection_sprite.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonig <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:10:24 by lkonig            #+#    #+#             */
/*   Updated: 2020/12/15 15:11:02 by lkonig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

#include <stdio.h> //

void			set_sprite_info(t_param *param, int k, int col)
{
	if (param->sprites[k].visible == -1)
	{
		param->sprites[k].visible = 1;
		param->sprites[k].col = col;
	}
	else if (col < param->sprites[k].col)
	{
		param->sprites[k].col = col;
	}
	else if (col > param->sprites[k].maxcol)
	{
		param->sprites[k].maxcol = col;
	}
}

int				inter_sprite(t_param *param, double angle, int col, int k)
{
	int			retv;
	int			reth;
	int			ret;

	ret = 0;
	retv = 0;
	reth = 0;
	angle = set_angle(angle);
	retv = inter_sp_v(param, angle, col, k);
	reth += inter_sp_h(param, angle, col, k);
	if (retv == 1 || reth == 1)
		ret = 1;
	return (ret);
}

int				inter_sp_v(t_param *p, double ang, int c, unsigned int k)
{
	double		tan_angle;
	t_point		b;

	b.col = c;
	tan_angle = set_tan(ang);
	b = init_ptv(ang, b, p, tan_angle);
	while (b.pos.y > 0 && b.pos.y < p->mapsize.y * 64 &&
		p->map[(int)b.pos.y][(int)b.pos.x] != '1')
	{
		if ((p->map[(int)b.pos.y][(int)b.pos.x] == '2')
			&& (check_inter_sp(b, p, k)))
		{
			set_sprite_info(p, (int)k, c);
			return (1);
		}
		else if ((p->map[(int)b.pos.y][(int)b.pos.x] == '2')
			&& (p->sprites[k].visible == 1
			&& p->sprites[k].maxcol == -1))
		{
			p->sprites[k].maxcol = c;
			return (1);
		}
		b = update_pointv(b, ang, tan_angle);
	}
	return (0);
}

int				inter_sp_h(t_param *p, double ang, int c, unsigned int k)
{
	t_point		a;
	double		tan_angle;

	a.col = c;
	tan_angle = set_tan(ang);
	a = init_pth(ang, a, p, tan_angle);
	while (a.pos.x > 0 && a.pos.x < ft_strlen(p->map[(int)a.pos.y]) &&
		p->map[(int)a.pos.y][(int)a.pos.x] != '1')
	{
		if ((p->map[(int)a.pos.y][(int)a.pos.x] == '2')
			&& (check_inter_sp(a, p, k)))
		{
			set_sprite_info(p, (int)k, c);
			return (1);
		}
		else if ((p->map[(int)a.pos.y][(int)a.pos.x] == '2')
			&& (p->sprites[k].visible == 1
			&& p->sprites[k].maxcol == -1))
		{
			p->sprites[k].maxcol = c;
			return (1);
		}
		a = update_pointh(a, ang, tan_angle);
	}
	return (0);
}
