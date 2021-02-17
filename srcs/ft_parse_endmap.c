/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_endmap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonig <lkonig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:08:59 by lkonig            #+#    #+#             */
/*   Updated: 2021/01/20 15:41:00 by lkonig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int			only_space(char *line, int i)
{
	while (line[i])
	{
		if (line[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

void		after_spaceline(t_param *param)
{
	param->startmap = 1;
	param->inmap = -1;
	param->endmap = -1;
	param->spline = -1;
}
