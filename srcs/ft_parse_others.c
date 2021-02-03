/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_others.c                                  :+:      :+:    :+:   */
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

int				parse_res(char *line, t_param *param)
{
	param->nbparam++;
	mlx_get_screen_size(param->mlx_ptr, &param->screen_res.x,
		&param->screen_res.y);
	while (*line == ' ' || *line == 'R')
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
	if (param->res.x < 150 || param->res.y < 100)
		return (-1);
	else if (param->res.x > 0 && param->res.y > 0)
		return (0);
	return (-1);
}

int			parse_col(char *line, t_param *param)
{
	int			i;
	char		letter;
	int			vir;

	vir = 1;
	i = 0;
	letter = 'A';
	while (*line == ' ' || *line == 'F' || *line == 'C')
	{
		if (*line == 'F' && letter == 'A')
			letter = 'F';
		else if (*line == 'C' && letter == 'A')
			letter = 'C';
		line++;
	}
	if (*line == ',')
		return (-1);
	while (i < 3 && *line && vir == 1)
	{
		vir = 0;
		while (*line == ' ')
			line++;
		if (!ft_isdigit(*line))
			return (-1);
		if (letter == 'F')
			param->fcol[i] = ft_atoi(line);
		if (letter == 'C')
			param->ccol[i] = ft_atoi(line);
		while (ft_isdigit(*line))
			line++;
		while ((*line == ' ' || *line == ',') && vir == 0)
		{
			if (*line == ',')
				vir = 1;
			line++;
		}
		i++;
	}
	if (vir == 1 || ft_isalpha(*line) || ft_isalnum(*line))
		return (-1);
	return (0);
}
