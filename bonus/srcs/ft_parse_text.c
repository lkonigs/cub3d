/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_text.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonig <lkonig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 10:42:23 by lkonig            #+#    #+#             */
/*   Updated: 2021/01/20 15:44:18 by lkonig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void			parse_text_sky_fl(t_param *param)
{
	int			u;

	if (!(param->fl_ptr = mlx_xpm_file_to_image(param->mlx_ptr,
		"textures/floor.xpm", &u, &u)))
		return (-1);
	if (!(param->sky_ptr = mlx_xpm_file_to_image(param->mlx_ptr,
		"textures/sky.xpm", &u, &u)))
		return (-1);
}

int				parse_text_sp(t_param *param, char *line, char a, char b)
{
	int			u;
	int			i;

	i = 2;
	while (line[i] == ' ' || line[i] == a || line[i] == b)
		i++;
	if (a == 'S' && b == ' ' && !param->sp_ptr)
	{
		if (!(param->sp_ptr = mlx_xpm_file_to_image(param->mlx_ptr,
			line + i, &u, &u)))
			return (-1);
		param->sp_text = mlx_get_data_addr(param->sp_ptr, &u, &u, &u);
	}
	return (0);
}

int				parse_text_ea_we(t_param *param, char *line, char a, char b)
{
	int			u;
	int			i;

	i = 2;
	while (line[i] == ' ' || line[i] == a || line[i] == b)
		i++;
	if (a == 'E' && b == 'A' && !param->ea_ptr)
	{
		if (!(param->ea_ptr = mlx_xpm_file_to_image(param->mlx_ptr,
			line + i, &u, &u)))
			return (-1);
		param->ea_text = mlx_get_data_addr(param->ea_ptr, &u, &u, &u);
	}
	else if (a == 'W' && b == 'E' && !param->we_ptr)
	{
		if (!(param->we_ptr = mlx_xpm_file_to_image(param->mlx_ptr,
			line + i, &u, &u)))
			return (-1);
		param->we_text = mlx_get_data_addr(param->we_ptr, &u, &u, &u);
	}
	else
		return (parse_text_sp(param, line, a, b));
	return (0);
}

int				parse_text_no_so(t_param *param, char *line, char a, char b)
{
	int			i;
	int			u;

	i = 2;
	while (line[i] == ' ' || line[i] == a || line[i] == b)
		i++;
	if (a == 'N' && b == 'O' && !param->no_ptr)
	{
		if (!(param->no_ptr = mlx_xpm_file_to_image(param->mlx_ptr,
			line + i, &u, &u)))
			return (-1);
		param->no_text = mlx_get_data_addr(param->no_ptr, &u, &u, &u);
		parse_text_sky_fl(param);
	}
	else if (a == 'S' && b == 'O' && !param->so_ptr)
	{
		if (!(param->so_ptr = mlx_xpm_file_to_image(param->mlx_ptr,
			line + i, &u, &u)))
			return (-1);
		param->so_text = mlx_get_data_addr(param->so_ptr, &u, &u, &u);
	}
	else
		return (parse_text_ea_we(param, line, a, b));
	return (0);
}

int				parse_text(char *line, t_param *param)
{
	int			i;
	char		a;
	char		b;

	i = 0;
	while (line[i] == ' ')
		i++;
	a = line[i++];
	b = line[i++];
	while (line[i] == ' ')
		i++;
	if (open(line + i, O_RDONLY) == -1)
		return (-1);
	param->nbparam++;
	if (parse_text_no_so(param, line, a, b) == -1)
		return (-1);
	return (0);
}
