/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonig <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:15:23 by lkonig            #+#    #+#             */
/*   Updated: 2020/10/27 15:16:28 by lkonig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void				nb_sprite(t_param *param)
{
	int i;
	int j;

	i = 0;
	while (i < param->mapsize.y)
	{
		j = 0;
		while (j < ft_strlen(param->tempmap[i]))
		{
			if (param->tempmap[i][j] == '2')
				param->nb_sprite++;
			j++;
		}
		i++;
	}
}

void				get_sprite(t_param *param, int i, int j, unsigned int k)
{
	param->sprites[k].pos.x = i + 32;
	param->sprites[k].pos.y = j + 32;
	param->sprites[k].dist = pow(param->player.pos.x
		- param->sprites[k].pos.x, 2)
		+ pow(param->player.pos.y - param->sprites[k].pos.y, 2);
	param->sprites[k].dist = sqrt(param->sprites[k].dist);
}

void				ft_sprite(t_param *param)
{
	unsigned int	k;
	int				i;
	int				j;

	k = 0;
	j = -1;
	while (k < param->nb_sprite && ++j < param->mapsize.y * 64)
	{
		i = -1;
		while (++i < ft_strlen(param->map[j]))
		{
			if (param->map[j][i] == '2')
			{
				init_sprite(param, k);
				if (param->sprites[k].pos.x == -1 && check_sp(param, i, j, k))
				{
					get_sprite(param, i, j, k);
					k++;
					i += 63;
				}
			}
		}
	}
}
