/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_turn_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonig <lkonig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:04:29 by lkonig            #+#    #+#             */
/*   Updated: 2021/01/20 15:37:46 by lkonig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void		turn_left(t_param *param)
{
	double	temp;

	param->player.angle += PTS;
	temp = param->player.dir.x;
	param->player.dir.x = param->player.dir.x * cos(-PTS * M_PI / 180)
		- param->player.dir.y * sin(-PTS * M_PI / 180);
	param->player.dir.y = temp * sin(-PTS * M_PI / 180)
		+ param->player.dir.y * cos(-PTS * M_PI / 180);
	temp = param->plane.vect.x;
	param->plane.vect.x = param->plane.vect.x * cos(-PTS * M_PI / 180)
		- param->plane.vect.y * sin(-PTS * M_PI / 180);
	param->plane.vect.y = temp * sin(-PTS * M_PI / 180)
		+ param->plane.vect.y * cos(-PTS * M_PI / 180);
}

void		turn_right(t_param *param)
{
	double	temp;

	param->player.angle -= PTS;
	temp = param->player.dir.x;
	param->player.dir.x = param->player.dir.x * cos(PTS * M_PI / 180)
		- param->player.dir.y * sin(PTS * M_PI / 180);
	param->player.dir.y = temp * sin(PTS * M_PI / 180)
		+ param->player.dir.y * cos(PTS * M_PI / 180);
	temp = param->plane.vect.x;
	param->plane.vect.x = param->plane.vect.x * cos(PTS * M_PI / 180)
		- param->plane.vect.y * sin(PTS * M_PI / 180);
	param->plane.vect.y = temp * sin(PTS * M_PI / 180)
		+ param->plane.vect.y * cos(PTS * M_PI / 180);
}

void		turn(t_param *param, int key)
{
	if (key == 65361)
		turn_left(param);
	else if (key == 65363)
		turn_right(param);
}
