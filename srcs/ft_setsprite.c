/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setwall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonig <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:19:22 by lkonig            #+#    #+#             */
/*   Updated: 2020/10/27 15:20:24 by lkonig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

#include <stdio.h> //

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
	int			i;
	int			j;
	double		pix;

	i = 0;
	j = get_j_sp(sp, param, &pix);
	sp.height *= 4 * param->res.x;
//	printf("init wall update ok\n");
	if (abs(j) > 500)
		printf("ERROR: let's do a check up\nsp.offset = %i\nsp.width = %i\nsp.pos.x = %f\n", sp.offset, sp.width, sp.pos.x);
	while (i < sp.height && i < param->res.y * param->res.x * 4)
	{
		if (!((int)param->sp_text[j] == 0
			&& (int)param->sp_text[j + 1] == 0
			&& (int)param->sp_text[j + 2] == 0))
			apply_text(str, param->sp_text, i, j);
		i += param->res.x * 4;
		pix++;
		while (pix >= sp.heat)
		{
			j += 256;
			pix -= sp.heat;
		}
	}
//	printf("update wall ok\n");
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

t_spwall		set_sprite(t_param *param, int k, t_multidouble transform, int screenx)
{
	t_spwall	sp;

	if ((double)param->sprites[k].dist > 0.01)
		sp.height = ceil(64.0 * (double)param->plane.dist
			/ (double)param->sprites[k].dist);
	else
		sp.height = 500000;
	sp.width = sp.height;
	param->sprites[k].col = screenx - (sp.width / 2);
	param->sprites[k].maxcol = screenx + (sp.width / 2);
	sp.heat = sp.height / 64.0;
	sp.pos.x = param->sprites[k].col;
	printf("SP#%u || tr.y = %f || sp.wid = %i || sp.pos.x = %f || screenx = %i || sp.dist = %f\n", k, transform.y, sp.width, sp.pos.x, screenx, param->sprites[k].dist);
	if (transform.y > 0)
		printf("----> SPRITE IS VISIBLE\n");
	sp.pos.y = (param->res.y - sp.height) / 2;
	if (param->sprites[k].col < 0)
	{
		sp.pos.x = 0;
//		sp.offset = (64 * (sp.pos.x - param->sprites[k].col)) / sp.width;
	}
/*	else if (param->sprites[k].maxcol == param->res.x - 1)
	{
		sp.offset = 0;
	}  */
	else 
		sp.offset = (64 * (sp.pos.x - param->sprites[k].col)) / sp.width;
	while (sp.pos.x++ < param->sprites[k].maxcol && sp.pos.x < param->res.x && sp.pos.x > 0)
	{
		if(transform.y > 0 && (transform.y < param->distbuf[(int)sp.pos.x] || param->sprites[k].dist < param->distbuf[(int)sp.pos.x]))
		{
			update_col(param, sp, param->imgstr);
		}
	/*	else if (transform.y > 0)
		{
			printf("SP#%u -----> trans.y = %f || wall dist = %f || sp dist = %f\n", k, transform.y, param->distbuf[(int)sp.pos.x], param->sprites[k].dist);
		} */
		
		sp.offset = (64 * (sp.pos.x - param->sprites[k].col)) / sp.width;
	}
	return (sp);
}
