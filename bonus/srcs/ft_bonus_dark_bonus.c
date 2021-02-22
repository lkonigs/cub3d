/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus_dark_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonig <lkonig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 15:19:22 by lkonig            #+#    #+#             */
/*   Updated: 2021/02/15 17:05:21 by lkonig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int					darken(int color, double distance)
{
	int				result;

	if (distance >= 1300)
		return (0);
	distance -= 300;
	distance = distance / 1000;
	color = color - (distance * color);
	result = color;
	if (result < 0)
		result = 0;
	return (result);
}

int					floor_darken(int color, double dist)
{
	if (dist < 3)
		return (color);
	if (dist > 13)
		return (0);
	dist -= 3;
	dist = dist / 10;
	color = color - (dist * color);
	if (color < 0)
		color = 0;
	return (color);
}

void				floor_apply(t_param *param, t_multiint i,
					char *text, double dist)
{
	param->imgstr[i.x++] = floor_darken(get_rgb((int)(text[i.y++])), dist);
	param->imgstr[i.x++] = floor_darken(get_rgb((int)(text[i.y++])), dist);
	param->imgstr[i.x++] = floor_darken(get_rgb((int)(text[i.y++])), dist);
}
