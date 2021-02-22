/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus_print_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonig <lkonig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 15:19:22 by lkonig            #+#    #+#             */
/*   Updated: 2021/02/15 17:05:21 by lkonig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void				print_bar(t_param *param, int i, int k)
{
	int				j;

	while (i < param->res.y - 20)
	{
		j = 0;
		while (j < 102)
		{
			param->imgstr[k++] = 0;
			param->imgstr[k++] = 0;
			param->imgstr[k++] = 0;
			k++;
			j++;
		}
		k += param->res.x * 4 - (102 * 4);
		i++;
	}
}

void				print_life(t_param *param, int i, int k)
{
	int				j;

	while (i < param->res.y - 21)
	{
		j = 0;
		while (j < param->player.hp)
		{
			param->imgstr[k++] = 0;
			if (param->player.hp >= 50)
				param->imgstr[k++] = 255;
			else
				param->imgstr[k++] = 0;
			if (param->player.hp >= 50)
				param->imgstr[k++] = 0;
			else
				param->imgstr[k++] = 255;
			k++;
			j++;
		}
		k += param->res.x * 4 - (param->player.hp * 4);
		i++;
	}
}

void				print_lifebar(t_param *param)
{
	int				i;
	int				k;

	i = param->res.y - 45;
	k = (param->res.x * 4 * i) + (4 * 18);
	print_bar(param, i, k);
	i = param->res.y - 44;
	k = (param->res.x * 4 * i) + (4 * 19);
	print_life(param, i, k);
}

void				print_gameover(t_param *param)
{
	mlx_string_put(param->mlx_ptr, param->win_ptr, param->res.x / 2 - 18,
	param->res.y / 2, WHITE, "G A M E  O V E R");
	mlx_string_put(param->mlx_ptr, param->win_ptr, param->res.x / 2 - 22,
	param->res.y / 2, WHITE, "G A M E  O V E R");
	mlx_string_put(param->mlx_ptr, param->win_ptr, param->res.x / 2 - 20,
	param->res.y / 2 - 2, WHITE, "G A M E  O V E R");
	mlx_string_put(param->mlx_ptr, param->win_ptr, param->res.x / 2 - 20,
	param->res.y / 2 + 2, WHITE, "G A M E  O V E R");
	mlx_string_put(param->mlx_ptr, param->win_ptr, param->res.x / 2 - 19,
	param->res.y / 2, RED, "G A M E  O V E R");
	mlx_string_put(param->mlx_ptr, param->win_ptr, param->res.x / 2 - 21,
	param->res.y / 2, RED, "G A M E  O V E R");
	mlx_string_put(param->mlx_ptr, param->win_ptr, param->res.x / 2 - 20,
	param->res.y / 2 - 1, RED, "G A M E  O V E R");
	mlx_string_put(param->mlx_ptr, param->win_ptr, param->res.x / 2 - 20,
	param->res.y / 2 + 1, RED, "G A M E  O V E R");
	mlx_string_put(param->mlx_ptr, param->win_ptr, param->res.x / 2 - 20,
	param->res.y / 2, RED, "G A M E  O V E R");
}

void				print_hud(t_param *param)
{
	int				color;
	char			*hp;

	hp = ft_itoa(param->player.hp);
	if (param->player.hp > 0)
	{
		mlx_string_put(param->mlx_ptr, param->win_ptr, 11,
		16, BLACK, "Press ESC to quit");
		mlx_string_put(param->mlx_ptr, param->win_ptr, 10,
		15, WHITE, "Press ESC to quit");
	}
	color = ((param->player.hp < 50) ? RED : GREEN);
	mlx_string_put(param->mlx_ptr, param->win_ptr,
					20, param->res.y - 50, WHITE, "Health : ");
	mlx_string_put(param->mlx_ptr, param->win_ptr,
			90, param->res.y - 50, color, hp);
	print_lifebar(param);
	if (param->player.hp <= 0)
		print_gameover(param);
	free(hp);
}
