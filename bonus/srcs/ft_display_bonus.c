/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonig <lkonig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:01:56 by lkonig            #+#    #+#             */
/*   Updated: 2021/01/20 15:33:27 by lkonig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void				sprite_set(t_param *param)
{
	unsigned int	k;
	double			inv;
	t_multidouble	transform;
	t_multiint		sprite;
	t_spwall		sp;

	k = param->nb_sprite;
	while (k > 0)
	{
		sprite.x = param->sprites[k - 1].pos.x - param->player.pos.x;
		sprite.y = param->sprites[k - 1].pos.y - param->player.pos.y;
		inv = 1.0 / (param->plane.vect.x * param->player.dir.y
			- param->player.dir.x * param->plane.vect.y);
		transform.x = inv * (param->player.dir.y * sprite.x
			- param->player.dir.x * sprite.y);
		transform.y = inv * (-param->plane.vect.y * sprite.x
			+ param->plane.vect.x * sprite.y);
		sp.screenx = (int)(param->res.x / 2) * (1 + transform.x / transform.y);
		set_sprite(param, k - 1, transform, sp.screenx);
		k--;
	}
}

int					create_image(t_param *param)
{
	int				col;
	double			angle;
	double			tmp;

	angle = param->player.angle + FOV / 2;
	sort_sprite(param);
	floor_texture(param);
	sky_texture(param);
	col = 0;
	while (angle > param->player.angle - FOV / 2 && col < param->res.x)
	{
		tmp = set_col(param, set_wall(param, intersection(param, col,
			angle), col), param->imgstr);
		param->distbuf[col] = tmp;
		angle -= param->plane.angles;
		col++;
	}
	sprite_set(param);
	return (0);
}

int					upd_image(t_param *param)
{
	create_image(param);
	mlx_put_image_to_window(param->mlx_ptr, param->win_ptr,
		param->imgptr, 0, 0);
	print_hud(param);
	return (0);
}

void				display(t_param *param, int save)
{
	int				u;

	param->plane.dist = (param->res.x / 2) / tan((FOV / 2) * M_PI / 180);
	param->plane.angles = (double)FOV / (double)param->res.x;
	if (save == 1)
		ft_save(param, "./save/save.bmp");
	param->win_ptr = NULL;
	param->win_ptr = mlx_new_window(param->mlx_ptr, param->res.x,
		param->res.y, "cub3D");
	if (param->win_ptr == NULL)
		ft_exit(param);
	param->imgptr = mlx_new_image(param->mlx_ptr, param->res.x, param->res.y);
	param->imgstr = mlx_get_data_addr(param->imgptr, &u, &u, &u);
	mlx_expose_hook(param->win_ptr, upd_image, (void *)param);
	mlx_hook(param->win_ptr, 33, 0, deal_end, (void *)param);
	mlx_hook(param->win_ptr, 2, (1L << 0), deal_key, (void *)param);
	mlx_loop(param->mlx_ptr);
}
