/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonig <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:04:29 by lkonig            #+#    #+#             */
/*   Updated: 2020/10/27 15:04:33 by lkonig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

#include <stdio.h> //

int			deal_key(int key, void *param)
{
	t_param	*par;

	par = (t_param *)param;
	if (key == 65307)
		ft_exit(par);
	else if ((key == 65361) || (key == 65363))
		turn(par, key);
	else if (key == 115)
		move(param, 0);
	else if (key == 119)
		move(param, 1);
	else if (key == 100)
		move(param, 2);
	else if (key == 97)
		move(param, 3);
	else
		return (0);
	upd_image(par);
	return (0);
}

void		turn(t_param *param, int key)
{
//	double	temp;
	if (key == 65361)
	{
		param->player.angle += PTS;
		param->player.dir.x = cos(param->player.angle * M_PI / 180);
		param->player.dir.y = - sin(param->player.angle * M_PI / 180);
	/*	temp = param->player.dir.x;
		param->player.dir.x = param->player.dir.x * cos(PTS) - param->player.dir.y * sin(PTS);
		param->player.dir.y = temp * sin(PTS) + param->player.dir.y * cos(PTS);
		temp = param->plane.vect.x;
		param->plane.vect.x = param->plane.vect.x * cos(PTS) - param->plane.vect.y * sin(PTS);
		param->plane.vect.y = temp * sin(PTS) + param->plane.vect.y * cos(PTS);
*/	}
	else if (key == 65363)
	{
		param->player.angle -= PTS;
		
		param->player.dir.x = cos(param->player.angle * M_PI / 180);
		param->player.dir.y = - sin(param->player.angle * M_PI / 180);
	/*	temp = param->player.dir.x;
		param->player.dir.x = param->player.dir.x * cos(-PTS) - param->player.dir.y * sin(-PTS);
		param->player.dir.y = temp * sin(-PTS) + param->player.dir.y * cos(-PTS);
		temp = param->plane.vect.x;
		param->plane.vect.x = param->plane.vect.x * cos(-PTS) - param->plane.vect.y * sin(-PTS);
		param->plane.vect.y = temp * sin(-PTS) + param->plane.vect.y * cos(-PTS);
*/	
	}
}

void		move(t_param *param, int type)
{
	int		x;
	int		y;

	if (type == 0 || type == 1)
	{
		x = round(PMS * cos(param->player.angle * M_PI / 180));
		y = round(PMS * -sin(param->player.angle * M_PI / 180));
	}
	else
	{
		x = round(PMS * cos((param->player.angle + 90) * M_PI / 180));
		y = round(PMS * -sin((param->player.angle + 90) * M_PI / 180));
	}
	if (type == 1 || type == 3)
	{
		x = param->player.pos.x + x;
		y = param->player.pos.y + y;
	}
	else
	{
		x = param->player.pos.x - x;
		y = param->player.pos.y - y;
	}
	apply_move(x, param->player.pos.y, 0, param);
	apply_move(y, param->player.pos.x, 1, param);
}

void		apply_move(int max_pos, int gv_pos, int k, t_param *param)
{
	unsigned int	j;

	if (k == 0)
	{
		if ((param->map[gv_pos][max_pos] != '1') &&
			(param->map[gv_pos][max_pos] != '2'))
			param->player.pos.x = max_pos;
	}
	else if (k == 1)
	{
		if ((param->map[max_pos][gv_pos] != '1') &&
			(param->map[max_pos][gv_pos] != '2'))
			param->player.pos.y = max_pos;
	}
	j = 0;
	while (j < param->nb_sprite)
	{
		param->sprites[j].dist = pow(param->player.pos.x -
			param->sprites[j].pos.x, 2) + pow(param->player.pos.y
			- param->sprites[j].pos.y, 2);
		param->sprites[j].dist = sqrt(param->sprites[j].dist);
		j++;
	}
}

int			deal_end(void *param)
{
	t_param	*pam;

	pam = (t_param *)param;
	ft_exit(pam);
	return (0);
}
