/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonig <lkonig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:19:22 by lkonig            #+#    #+#             */
/*   Updated: 2021/01/20 15:45:01 by lkonig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int				get_j_sp(t_spwall sp, t_param *param, double *pix)
{
	double		j;
	int			ret;

	ret = 4 * sp.offset;
	*pix = 0.0;
	if (sp.height > param->res.y)
	{
		j = (double)((64.0 * ((float)((sp.height
			- param->res.y) / 2) / sp.height)));
		*pix = (j - (int)j) * sp.heat;
		j = (int)j;
		j *= 256;
		ret += j;
	}
	return (ret);
}

void			update_wall(t_spwall sp, char *str, t_param *param)
{
	t_multiint	i;
	double		pix;

	i.x = 0;
	i.y = get_j_sp(sp, param, &pix);
	sp.height *= 4 * param->res.x;
	while (i.x < sp.height && i.x < param->res.y * param->res.x * 4)
	{
		if (!((int)param->sp_text[i.y] == 0
			&& (int)param->sp_text[i.y + 1] == 0
			&& (int)param->sp_text[i.y + 2] == 0))
			apply_text(str, param->sp_text, i, sp.dist);
		i.x += param->res.x * 4;
		pix++;
		while (pix >= sp.heat)
		{
			i.y += 256;
			pix -= sp.heat;
		}
	}
}

void			update_col(t_param *param, t_spwall sp, char *str)
{
	int			i;

	i = sp.pos.x * 4;
	sp.pos.y *= param->res.x * 4;
	while (i < sp.pos.y)
		i += param->res.x * 4;
	update_wall(sp, str + i, param);
}

t_spwall		set_sprite(t_param *p, int k, t_multidouble trsf, long int scrx)
{
	t_spwall	sp;

	sp.height = ceil(64.0 * (double)p->plane.dist
		/ (double)p->sprites[k].dist);
	if ((double)p->sprites[k].dist <= 0.01)
		sp.height = 500000;
	sp.width = sp.height;
	sp.dist = p->sprites[k].dist;
	p->sprites[k].col = scrx - (sp.width / 2);
	p->sprites[k].maxcol = scrx + (sp.width / 2);
	sp.heat = sp.height / 64.0;
	sp.pos.x = p->sprites[k].col;
	sp.pos.y = (p->res.y - sp.height) / 2;
	if (p->sprites[k].col < 0)
		sp.pos.x = 0;
	while (sp.pos.x < p->sprites[k].maxcol && sp.pos.x < p->res.x
		&& sp.pos.x >= 0)
	{
		sp.offset = (64 * (sp.pos.x - p->sprites[k].col)) / sp.width;
		if (trsf.y > 0.000000000001 && (trsf.y < p->distbuf[(int)sp.pos.x]
			|| p->sprites[k].dist < p->distbuf[(int)sp.pos.x]))
			update_col(p, sp, p->imgstr);
		sp.pos.x++;
	}
	return (sp);
}
