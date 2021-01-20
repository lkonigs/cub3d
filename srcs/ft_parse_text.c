/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_text.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonig <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 10:42:23 by lkonig            #+#    #+#             */
/*   Updated: 2021/01/20 10:42:23 by lkonig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void			parse_text_sp(t_param *param, char *line, int i)
{
	int			u;

	if (line[0] == 'S' && line[1] == ' ')
	{
		i = 2;
		if (!(param->sp_ptr = mlx_xpm_file_to_image(param->mlx_ptr,
			line + i, &u, &u)))
			error(6, param);
		param->sp_text = mlx_get_data_addr(param->sp_ptr, &u, &u, &u);
	}
}

void			parse_text_ea_we(t_param *param, char *line, int i)
{
	int			u;

	if (line[0] == 'E' && line[1] == 'A')
	{
		if (!(param->ea_ptr = mlx_xpm_file_to_image(param->mlx_ptr,
			line + i, &u, &u)))
			error(6, param);
		param->ea_text = mlx_get_data_addr(param->ea_ptr, &u, &u, &u);
	}
	else if (line[0] == 'W' && line[1] == 'E')
	{
		if (!(param->we_ptr = mlx_xpm_file_to_image(param->mlx_ptr,
			line + i, &u, &u)))
			error(6, param);
		param->we_text = mlx_get_data_addr(param->we_ptr, &u, &u, &u);
	}
	else
		parse_text_sp(param, line, i);
}

void			parse_text_no_so(t_param *param, char *line)
{
	int			i;
	int			u;

	i = 3;
	while (line[i] == ' ')
		i++;
	if (line[0] == 'N' && line[1] == 'O')
	{
		if (!(param->no_ptr = mlx_xpm_file_to_image(param->mlx_ptr,
			line + i, &u, &u)))
			error(6, param);
		param->no_text = mlx_get_data_addr(param->no_ptr, &u, &u, &u);
	}
	else if (line[0] == 'S' && line[1] == 'O')
	{
		if (!(param->so_ptr = mlx_xpm_file_to_image(param->mlx_ptr,
			line + i, &u, &u)))
			error(6, param);
		param->so_text = mlx_get_data_addr(param->so_ptr, &u, &u, &u);
	}
	else
		parse_text_ea_we(param, line, i);
}

int				parse_text(char *line, t_param *param)
{
	int			i;

	i = 0;
	while (line[i] == ' ')
		i++;
	i += 2;
	while (line[i] == ' ')
		i++;
	if (open(line + i, O_RDONLY) == -1)
		error(13, param);
	parse_text_no_so(param, line);
	return (0);
}
