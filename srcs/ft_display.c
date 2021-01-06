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

#include <stdio.h> //

void	sprite_disp(t_param *param, t_spwall sp, t_multidouble transform, double *distbuf)
{
	int			i;
//	update_wall(sp, param->imgstr + i, param);

	int	col;
//	int	row;
	
	col = sp.drawst.x;
	sp.pos.x = col;
	sp.pos.y = (param->res.y - sp.height) / 2;
	sp.offset = (64 * (col - sp.drawst.x)) / (sp.drawend.x - sp.drawst.x);
	printf("we get here!\n");
	while (col++ < sp.drawend.x)
	{
//      int texX = (int)(256 * (col - (- sp.width/ 2 + sp.screen.x)) * 64 / sp.width) / 256;
        if(transform.y > 0 && col > 0 && col < param->res.x && transform.y < distbuf[col])
        {
			i = sp.pos.x * 4;
			sp.pos.y *= param->res.x * 4;
			while (i < sp.pos.y)
				i += param->res.x * 4;
/*			row = sp.drawst.y;
			while (row++ < sp.drawend.y)
			{
        		int d = (row) * 256 - param->res.y * 128 + sp.height * 128; //256 and 128 factors to avoid floats
     	    	int texY = ((d * 64) / sp.height) / 256;
   	    		int color = param->sp_text[64 * texY + texX]; //get current color from the texture
    	    	if((color & 0x00FFFFFF) != 0) param->imgstr[5] = color; //paint pixel if it isn't black, black is the invisible color
        	}
*/			update_wall(sp, param->imgstr + i, param);
//			sp.offset = (64 * (sp.pos.x - param->sprites[k].col)) / sp.width;
		}
    } 
}

void				sprite_set(t_param *param)
{
	unsigned int	k;
	double			inv;
	t_multidouble	transform;
	t_multiint	sprite;
	t_spwall		sp;

	k = param->nb_sprite;
//	printf("________________________________\n\n");
	while (k > 0)
	{
//		printf("-----------SPRITE #%u----------\n_____x = %i___||____y = %i\n", k, param->sprites[k - 1].pos.x, param->sprites[k - 1].pos.y);
//		printf("-------------PLAYER------------\n_____x = %i___||____y = %i\n", param->player.pos.x, param->player.pos.y);
		sprite.x = param->sprites[k - 1].pos.x - param->player.pos.x;
		sprite.y = param->sprites[k - 1].pos.y - param->player.pos.y;
//		printf("----------RELATIVE POS---------\n_____x = %i___||____y = %i\n", sprite.x, sprite.y);



		inv = 1.0 / (param->plane.vect.x * param->player.dir.y - param->player.dir.x * param->plane.vect.y);
		transform.x = inv * (param->player.dir.y * sprite.x - param->player.dir.x * sprite.y);
		transform.y = inv * (- param->plane.vect.y * sprite.x + param->plane.vect.x * sprite.y);
		sp.screen.x = (int)(param->res.x / 2) * (1 + transform.x / transform.y);
	//	sp.screen.x = (1 + transform.x / transform.y) / 2 * param->res.y;
//		printf("---------OTHER INFOS-----------\nTRANSFORMX = %f || TRANSFORMY = %f\nSCREENX = %i\n", transform.x, transform.y, sp.screen.x);
//		printf("DIR.X = %f || DIR.Y = %f\n", param->player.dir.x, param->player.dir.y);
//		printf("PLANE.X = %f || PLANE.Y = %f\n", param->plane.vect.x, param->plane.vect.y);

	//	printf("Sprite #%u - transform.y = %f\n", k - 1, transform.y);
	/*	sp.height = abs(param->res.y / transform.y);
		printf("sp.height value = %lld\n", sp.height);
		sp.drawst.y = (param->res.y - sp.height) / 2;
		if (sp.drawst.y < 0)
			sp.drawst.y = 0;
		sp.drawend.y = (param->res.y + sp.height) / 2;
		if (sp.drawend.y >= param->res.y)
			sp.drawend.y = param->res.y - 1;
		
		printf("value of param->res.y = %i\ntransform.y = %f\n", param->res.y, transform.y);
		sp.width = abs((int)param->res.y / transform.y);
		sp.drawst.x = -sp.width / 2 + sp.screen.x;
		if (sp.drawst.x < 0)
			sp.drawst.x = 0;
		sp.drawend.x = sp.screen.x + (sp.width / 2);
		if (sp.drawend.x >= param->res.x)
			sp.drawend.x = param->res.x - 1;
		sprite_disp(param, sp, transform, distbuf); */
		set_sprite(param, k - 1, transform, sp.screen.x);
	//	printf("-------------------------------\n\n");
		k--;
	}
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
//	upd_image(param);
	mlx_expose_hook(param->win_ptr, upd_image, (void *)param);
	mlx_hook(param->win_ptr, 33, 0, deal_end, (void *)param);
	mlx_hook(param->win_ptr, 2, (1L << 0), deal_key, (void *)param);
	mlx_loop(param->mlx_ptr);
}

int					create_image(t_param *param)
{
	int				col;
	int				u;
	double			angle;
	double			tmp;
//	double			distbuf[param->res.x];
//	unsigned int	k;

	param->imgptr = mlx_new_image(param->mlx_ptr, param->res.x, param->res.y);
	param->imgstr = mlx_get_data_addr(param->imgptr, &u, &u, &u);
	angle = param->player.angle + FOV / 2;
	col = 0;
	sort_sprite(param);
	while (angle > param->player.angle - FOV / 2 && col < param->res.x)
	{
		tmp = set_col(param, set_wall(param, intersection(param, col, angle), col),
			param->imgstr);
		param->distbuf[col] = tmp;
		angle -= param->plane.angles;
		col++;
	}
/*	correct_sprite(param);
	display_sprite(param); */
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
