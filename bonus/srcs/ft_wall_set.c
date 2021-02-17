/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wall_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonig <lkonig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:19:22 by lkonig            #+#    #+#             */
/*   Updated: 2021/01/20 15:45:21 by lkonig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void			set_mid(t_wall w, char *str, t_param *param)
{
	char		*text;
	t_multiint	i;
	double		pix;

	i.x = 0;
	i.y = get_j(w, param, &pix);
	w.height *= 4 * param->res.x;
	text = set_text(w, param);
	while (i.x < w.height && i.x < param->res.y * param->res.x * 4)
	{
		apply_text(str, text, i, w.dist);
		i.x += param->res.x * 4;
		pix++;
		while (pix >= w.heat)
		{
			i.y += 256;
			pix -= w.heat;
		}
	}
}

int				set_sky(int i, t_param *param, t_wall w)
{
	while (i < w.pos.y)
	{
		i++;
		i++;
		i++;
		i += param->res.x * 4 - 3;
	}
	return (i);
}

void			set_floor(int i, t_param *param)
{
	while (i < param->res.x * param->res.y * 4 && i > 0)
	{
		param->imgstr[i] = (char)param->fcol[2];
		i++;
		param->imgstr[i] = (char)param->fcol[1];
		i++;
		param->imgstr[i] = (char)param->fcol[0];
		i++;
		i += param->res.x * 4 - 3;
	}
}

t_wall			set_wall(t_param *param, t_point p, int col)
{
	t_wall		w;

	w.text = p.text;
	w.dist = p.dist;
	if ((double)p.dist > 0.01)
		w.height = ceil(64.0 * (double)param->plane.dist / (double)p.dist);
	else
		w.height = 500000;
	w.heat = w.height / 64.0;
	w.pos.x = col;
	w.pos.y = (param->res.y - w.height) / 2;
	if (w.text == 'N' || w.text == 'S')
		w.offset = (int)p.pos.x % WH;
	else if (w.text == 'W' || w.text == 'E')
		w.offset = (int)p.pos.y % WH;
	return (w);
}

double			set_col(t_param *param, t_wall w, char *str)
{
	int			i;

	i = w.pos.x * 4;
	w.pos.y *= param->res.x * 4;
	i = set_sky(i, param, w);
	set_mid(w, str + i, param);
	i += w.height * 4 * param->res.x;
	return (w.dist);
}
