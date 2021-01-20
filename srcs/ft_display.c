/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonig <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:01:56 by lkonig            #+#    #+#             */
/*   Updated: 2020/10/27 15:03:34 by lkonig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
		inv = 1.0 / (param->plane.vect.y * param->player.dir.x
			- param->player.dir.y * param->plane.vect.x);
		transform.x = inv * (param->player.dir.x * sprite.y
			- param->player.dir.y * sprite.x);
		transform.y = inv * (-param->plane.vect.x * sprite.y
			+ param->plane.vect.y * sprite.x);
		sp.screenx = (int)(param->res.x / 2) * (1 + transform.x / transform.y);
		set_sprite(param, k - 1, transform, sp.screenx);
		k--;
	}
}

int					create_image(t_param *param)
{
	int				col;
	int				u;
	double			angle;
	double			tmp;

	param->imgptr = mlx_new_image(param->mlx_ptr, param->res.x, param->res.y);
	param->imgstr = mlx_get_data_addr(param->imgptr, &u, &u, &u);
	angle = param->player.angle + FOV / 2;
	col = 0;
	sort_sprite(param);
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
	mlx_destroy_image(param->mlx_ptr, param->imgptr);
	return (0);
}

void				display(t_param *param, int save)
{
	param->plane.dist = (param->res.x / 2) / tan((FOV / 2) * M_PI / 180);
	param->plane.angles = (double)FOV / (double)param->res.x;
	if (save == 1)
		ft_save(param, "./save/save.bmp");
	param->win_ptr = mlx_new_window(param->mlx_ptr, param->res.x,
		param->res.y, "Cub3D");
	if (param->win_ptr == NULL)
		ft_exit(param);
	mlx_expose_hook(param->win_ptr, upd_image, (void *)param);
	mlx_hook(param->win_ptr, 33, 0, deal_end, (void *)param);
	mlx_hook(param->win_ptr, 2, (1L << 0), deal_key, (void *)param);
	mlx_loop(param->mlx_ptr);
}
