/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_res.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonig <lkonig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:15:23 by lkonig            #+#    #+#             */
/*   Updated: 2021/01/20 15:43:50 by lkonig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void			res_comp(int tmp, t_param *param, int i)
{
	if (i == 0)
	{
		if (tmp < param->screen_res.x)
			param->res.x = tmp;
		else
			param->res.x = param->screen_res.x;
	}
	else if (i == 1)
	{
		if (tmp < param->screen_res.y)
			param->res.y = tmp;
		else
			param->res.y = param->screen_res.y;
	}
}

int				res_check(t_param *param)
{
	if (param->res.x < 150 || param->res.y < 100)
		return (-1);
	else if (param->res.x > 0 && param->res.y > 0)
		return (0);
	return (-1);
}

int				parse_res(char *line, t_param *param)
{
	param->nbparam++;
	mlx_get_screen_size(param->mlx_ptr, &param->screen_res.x,
		&param->screen_res.y);
	while (*line == ' ')
		line++;
	param->save_res.x = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	while (*line == ' ')
		line++;
	param->save_res.y = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	while (*line)
	{
		if (*line != ' ')
			return (-1);
		line++;
	}
	res_comp(param->save_res.x, param, 0);
	res_comp(param->save_res.y, param, 1);
	return (res_check(param));
}
