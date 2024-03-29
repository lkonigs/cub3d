/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonig <lkonig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:04:29 by lkonig            #+#    #+#             */
/*   Updated: 2021/01/20 15:37:24 by lkonig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void		apply_move(int max_pos, int gv_pos, int k, t_param *param)
{
	unsigned int	j;

	if (k == 0)
	{
		if (check_proximity_x(max_pos, gv_pos, param))
			param->player.pos.x = max_pos;
	}
	else if (k == 1)
	{
		if (check_proximity_y(max_pos, gv_pos, param))
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

int			deal_key(int key, void *param)
{
	t_param	*par;

	par = (t_param *)param;
	if (key == 65307 || par->player.hp <= 0)
	{
		if (par->player.hp <= 0)
			sleep(2);
		ft_exit(par);
	}
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

int			deal_end(void *param)
{
	t_param	*pam;

	pam = (t_param *)param;
	ft_exit(pam);
	return (0);
}
