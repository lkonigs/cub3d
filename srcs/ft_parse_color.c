/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonig <lkonig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:15:23 by lkonig            #+#    #+#             */
/*   Updated: 2021/01/20 15:43:50 by lkonig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char			col_letter(char *line, char letter)
{
	if (*line == 'F' && letter == 'A')
		letter = 'F';
	else if (*line == 'C' && letter == 'A')
		letter = 'C';
	return (letter);
}

void			col_apply(char *line, t_param *param, int i, char l)
{
	if (l == 'F')
		param->fcol[i] = ft_atoi(line);
	if (l == 'C')
		param->ccol[i] = ft_atoi(line);
}

int				col_check(int vir, char *line)
{
	if (vir == 1 || ft_isalpha(*line) || ft_isalnum(*line))
		return (-1);
	return (0);
}

int				col_vir(char *line, int vir)
{
	if (*line == ',')
		vir = 1;
	return (vir);
}

int				parse_col(char *line, t_param *param)
{
	int			i;
	char		letter;
	int			vir;

	vir = 1;
	i = 0;
	letter = 'A';
	param->nbparam++;
	while (*line == ' ' || *line == 'F' || *line == 'C')
		letter = col_letter(line++, letter);
	if (*line == ',')
		return (-1);
	while (i < 3 && *line && vir == 1 && (vir = 0) == 0)
	{
		while (*line == ' ')
			line++;
		if (!ft_isdigit(*line))
			return (-1);
		col_apply(line, param, i++, letter);
		while (ft_isdigit(*line))
			line++;
		while ((*line == ' ' || *line == ',') && vir == 0)
			vir = col_vir(line++, vir);
	}
	return (col_check(vir, line));
}
