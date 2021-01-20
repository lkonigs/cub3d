/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonig <lkonig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:05:23 by lkonig            #+#    #+#             */
/*   Updated: 2021/01/20 15:38:10 by lkonig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_param_player(t_param *param)
{
	param->player.angle = -1;
	param->player.pos.x = -1;
	param->player.pos.y = -1;
	param->player.dir.x = 0;
	param->player.dir.y = 0;
	param->plane.angles = -1;
	param->plane.dist = -1;
	param->plane.vect.x = 0;
	param->plane.vect.y = 0;
	param->mapsize = (t_multiint){.x = 0, .y = 0};
	param->res = (t_multiint){.x = -1, .y = -1};
	param->screen_res = (t_multiint){.x = -1, .y = -1};
	param->nb_sprite = 0;
}

void	init_param(t_param *param)
{
	int	i;

	i = 0;
	param->tempmap = NULL;
	if (!(param->fcol = (int *)malloc(sizeof(int) * 3))
		|| !(param->ccol = (int *)malloc(sizeof(int) * 3)))
		error(1, param);
	if (!(param->tempmap = malloc(sizeof(char *) * 100)))
		error(1, param);
	while (i < 100)
		param->tempmap[i++] = NULL;
	param->ccol[0] = -1;
	param->fcol[0] = -1;
	param->map = NULL;
	param->no_ptr = NULL;
	param->ea_ptr = NULL;
	param->so_ptr = NULL;
	param->we_ptr = NULL;
	param->sp_ptr = NULL;
	param->win_ptr = NULL;
	param->mlx_ptr = NULL;
	init_param_player(param);
	if (!(param->mlx_ptr = mlx_init()))
		error(0, param);
}

int		init_player(t_param *param, char dir, int pos_x, int pos_y)
{
	param->player.pos.x = pos_x + 32;
	param->player.pos.y = pos_y + 32;
	if (dir == 'N')
		param->player.angle = 90;
	else if (dir == 'W')
		param->player.angle = 180;
	else if (dir == 'S')
		param->player.angle = 270;
	else if (dir == 'E')
		param->player.angle = 0;
	else
	{
		error(9, param);
	}
	param->map[pos_y][pos_x] = '0';
	return (0);
}

void	init_sprite(t_param *param, unsigned int k)
{
	param->sprites[k].pos.x = -1;
	param->sprites[k].pos.y = -1;
	param->sprites[k].col = -1;
	param->sprites[k].midcol = -1;
	param->sprites[k].maxcol = -1;
	param->sprites[k].dist = -1;
	param->sprites[k].visible = -1;
}
