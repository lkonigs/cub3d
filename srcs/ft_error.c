/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonig <lkonig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:25:30 by lkonig            #+#    #+#             */
/*   Updated: 2021/01/20 15:36:33 by lkonig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

#include <stdio.h> //

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

void	error_parse(int i, t_param *param)
{
	ft_putstr ("Error\n");
	if (i == 1)
		ft_putstr("Config file: does not end with the last map line\n");
	else if (i == 2)
		ft_putstr("F/C: wrong format\n");
	else if (i == 3)
		ft_putstr("Resolution: wrong format or values (maybe too low)\n");
	else if (i == 4)
		ft_putstr("Config file: invalid key or non empty line (space)\n");
	else if (i == 5)
		ft_putstr("Config file: double line of '1' or attempt to create a second map\n");
	else if (i == 6)
		ft_putstr("Texture: error while turning xpm file into mlx image\n");
	else if (i == 7)
		ft_putstr("Texture: invalid path or file (may be due to extra spaces)\n");
	else if (i == 8)
		ft_putstr("Map: map is open or invalid (empty line, wrong direction)\n");
	else if (i == 9)
		ft_putstr("Error while allocating memory\n");
	ft_exit(param);
} 

void	error(int i, t_param *param)
{
	ft_putstr("Error\n");
	if (i == 0)
		ft_putstr("MLX: mlx_init failed\n");
	else if (i == 1)
		ft_putstr("Error while allocating memory\n");
	else if (i == 2)
		ft_putstr("Texture: a texture is missing\n");
	else if (i == 3)
		ft_putstr("R: wrong or missing resolution values in the config file\n");
	else if (i == 4)
		ft_putstr("Config file: Wrong number or disposition of parameters given in the .cub file\n");
	else if (i == 5)
		ft_putstr("F/C: wrong or missing color values in the config file\n");
	else if (i == 6)
		ft_putstr("Map: missing map\n");
	else if (i == 7)
		ft_putstr("Map: missing player/over one player\n");	
	else if (i == 8)
		ft_putstr("Map: map is open or invalid\n");
	else if (i == 9)
		ft_putstr("Wrong direction or number of players in the config file\n");
	else if (i == 10)
		ft_putstr("Player: no player detected on the map\n");
	else if (i == 12)
		ft_putstr("Raycasting: could not reach a proper wall intersection\n");
	ft_exit(param);
}

void	ft_exit_mlx(t_param *param)
{
	if (param->imgptr)
		mlx_destroy_image(param->mlx_ptr, param->imgptr);
	if (param->no_ptr)
		mlx_destroy_image(param->mlx_ptr, param->no_ptr);
	if (param->so_ptr)
		mlx_destroy_image(param->mlx_ptr, param->so_ptr);
	if (param->ea_ptr)
		mlx_destroy_image(param->mlx_ptr, param->ea_ptr);
	if (param->we_ptr)
		mlx_destroy_image(param->mlx_ptr, param->we_ptr);
	if (param->sp_ptr)
		mlx_destroy_image(param->mlx_ptr, param->sp_ptr);
	if (param->win_ptr)
		mlx_destroy_window(param->mlx_ptr, param->win_ptr);
	param->win_ptr = NULL;
	mlx_destroy_display(param->mlx_ptr);
	free(param->mlx_ptr);
}

void	ft_exit(t_param *param)
{
	int		i;

	i = -1;
	while (i++ < param->mapsize.y)
		free(param->tempmap[i]);
	free(param->tempmap);
	i = 0;
	if (param->map)
	{
		while (i < param->mapsize.y * 64)
			free(param->map[i++]);
	}
	free(param->map);
	free(param->fcol);
	free(param->ccol);
	if (param->mlx_ptr)
		ft_exit_mlx(param);
	free(param);
	exit(0);
}
