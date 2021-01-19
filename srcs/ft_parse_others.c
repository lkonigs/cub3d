/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_others.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonig <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:15:23 by lkonig            #+#    #+#             */
/*   Updated: 2020/10/27 15:16:28 by lkonig           ###   ########.fr       */
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
	int			tmpresx;
	int			tmpresy;

	if ((param->res.x != -1) || (param->res.y != -1))
		return (-1);
	mlx_get_screen_size(param->mlx_ptr, &param->screen_res.x,
		&param->screen_res.y);
	while (*line == ' ' || *line == 'R')
		line++;
	tmpresx = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	tmpresy = ft_atoi(line);
	res_comp(tmpresx, param, 0);
	res_comp(tmpresy, param, 1);
	if (param->res.x < 150 || param->res.y < 100)
		error(3, param);
	else if (param->res.x > 0 && param->res.y > 0)
		return (0);
	return (-1);
}

void			parse_col(char *line, t_param *param)
{
	int			i;
	char		letter;

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
	while (i < 3 && *line)
	{
		if (letter == 'F')
			param->fcol[i] = ft_atoi(line);
		if (letter == 'C')
			param->ccol[i] = ft_atoi(line);
		while (ft_isdigit(*line))
			line++;
		if (*line == ',')
			line++;
		i++;
	}
}

void			get_text(t_param *param, char *line)
{
	int			i;
	int			u;
//	void		*ptr;
//	char		*text;

//	ptr = NULL;
//	text = mlx_get_data_addr(ptr, &u, &u, &u);
	i = 3;
	if (line[0] == 'N' && line[1] == 'O')
	{
	//	param->no_text = text;
		ft_putchar('N');
		if (!(param->no_ptr = mlx_xpm_file_to_image(param->mlx_ptr, line + i, &u, &u)))
			error(6, param);
		param->no_text = mlx_get_data_addr(param->no_ptr, &u, &u, &u);
	}
	else if (line[0] == 'S' && line[1] == 'O')
	{
		ft_putchar('S');
		if (!(param->so_ptr = mlx_xpm_file_to_image(param->mlx_ptr, line + i, &u, &u)))
			error(6, param);
		param->so_text = mlx_get_data_addr(param->so_ptr, &u, &u, &u);
	}
	else if (line[0] == 'E' && line[1] == 'A')
	{
		if (!(param->ea_ptr = mlx_xpm_file_to_image(param->mlx_ptr, line + i, &u, &u)))
			error(6, param);
		param->ea_text = mlx_get_data_addr(param->ea_ptr, &u, &u, &u);
	}
	else if (line[0] == 'W' && line[1] == 'E')
	{
		if (!(param->we_ptr = mlx_xpm_file_to_image(param->mlx_ptr, line + i, &u, &u)))
			error(6, param);
		param->we_text = mlx_get_data_addr(param->we_ptr, &u, &u, &u);
	}
	else if (line[0] == 'S' && line[1] == ' ')
	{
		i = 2;
		if (!(param->sp_ptr = mlx_xpm_file_to_image(param->mlx_ptr, line + i, &u, &u)))
			error(6, param);
		param->sp_text = mlx_get_data_addr(param->sp_ptr, &u, &u, &u);
	}
}

int				parse_text(char *line, t_param *param)
{
	int			i;
//	int			u;

	i = 0;
	while (line[i] == ' ')
		i++;
	i += 2;
	while (line[i] == ' ')
		i++;
	if (open(line + i, O_RDONLY) == -1)
		error(13, param);
	get_text(param, line);
//	free(ptr);
/*	if (ptr)
		mlx_destroy_image(param->mlx_ptr, ptr); */
//	ptr = NULL;
//	free(text);
	return (0);
}
