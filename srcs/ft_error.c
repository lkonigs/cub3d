/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonig <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:25:30 by lkonig            #+#    #+#             */
/*   Updated: 2020/10/27 15:25:31 by lkonig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	error_init(int i)
{
	ft_putstr("Error\n");
	if (i == 0)
		ft_putstr("Missing arguments\n");
	else if (i == 1)
		ft_putstr("Too many arguments\n");
	else if (i == 2)
		ft_putstr("Wrong input - Check how you spelled '--save'\n");
	else if (i == 3)
		ft_putstr("Invalid map format (it should be '.cub')\n");
	else if (i == 4)
		ft_putstr("Opening the .cub file went wrong\n");
	else if (i == 5)
		ft_putstr("Error while allocating memory\n");
	exit(0);
}

void	error(int i, t_param *param)
{
	ft_putstr("Error\n");
	if (i == 0)
		ft_putstr("Could not connect to the mlx (mlx_init)\n");
	else if (i == 1)
		ft_putstr("Error while allocating memory\n");
	else if (i == 2)
		ft_putstr("Wrong parameter in the .cub file (R)\n");
	else if (i == 3)
		ft_putstr("Resolution is too low\n");
	else if (i == 4)
		ft_putstr("Wrong parameter in the .cub file (F or C)\n");
	else if (i == 5)
		ft_putstr("Wrong color values for F or C\n");
	else if (i == 6)
		ft_putstr("Error while turning xpm file into mlx image\n");
	else if (i == 7)
		ft_putstr("Wrong parameter in the .cub file (texture)\n");
	else if (i == 8)
		ft_putstr("Wrong map values\n");
	else if (i == 9)
		ft_putstr("Wrong direction or number of players in the config file\n");
	else if (i >= 10)
		error_more(i);
	ft_exit(param);
}

void	error_more(int i)
{
	if (i == 10)
		ft_putstr("Missing values in the config file\n");
	else if (i == 11)
		ft_putstr("Error creating the window with mlx\n");
	else if (i == 12)
		ft_putstr("Could not reach a proper wall intersection\n");
	else if (i == 13)
		ft_putstr("Error in opening .xpm file\n");
	else if (i == 14)
		ft_putstr("Wrong number of sprites\n");
}

void	ft_exit(t_param *param)
{
	int		i;

	i = -1;
	while (i++ < param->mapsize.y)
		free(param->tempmap[i]);
	free(param->tempmap);
	while (++i < param->mapsize.y * 64)
		free(param->map[i]);
	free(param->map);
	free(param->fcol);
	free(param->ccol);
	if (param->win_ptr)
		mlx_destroy_window(param->mlx_ptr, param->win_ptr);
	free(param->mlx_ptr);
	free(param);
	exit(0);
}
