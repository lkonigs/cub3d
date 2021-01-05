/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setwall_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonig <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:19:22 by lkonig            #+#    #+#             */
/*   Updated: 2020/10/27 15:20:24 by lkonig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int			get_j(t_wall w, t_param *param, double *pix)
{
	double	j;
	int		ret;

	ret = 4 * w.offset;
	*pix = 0.0;
	if (w.height > param->res.y)
	{
		j = (double)((64.0 * ((float)((w.height - param->res.y) / 2)
			/ w.height)));
		*pix = (j - (int)j) * w.heat;
		j = (int)j;
		j *= 256;
		ret += j;
	}
	return (ret);
}

char		*set_text(t_wall w, t_param *param)
{
	if (w.text == 'N')
		return (param->no_text);
	else if (w.text == 'S')
		return (param->so_text);
	else if (w.text == 'W')
		return (param->we_text);
	else
		return (param->ea_text);
}

int			get_rgb(int color)
{
	if (color >= 0)
		return (color);
	color = 256 + color;
	return (color);
}

void		apply_text(char *str, char *text, int i, int j)
{
	str[i] = get_rgb((int)text[j]);
	i++;
	j++;
	str[i] = get_rgb((int)text[j]);
	i++;
	j++;
	str[i] = get_rgb((int)text[j]);
}
