/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonig <lkonig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:25:30 by lkonig            #+#    #+#             */
/*   Updated: 2021/01/20 15:36:33 by lkonig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
