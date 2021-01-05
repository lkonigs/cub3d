/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonig <lkonig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 22:58:05 by lkonig            #+#    #+#             */
/*   Updated: 2020/04/28 22:58:06 by lkonig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_strlen(const char *s)
{
	int			i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

size_t				ft_intlen(int nbr)
{
	int int_len;

	int_len = 0;
	if (nbr < 0)
		int_len++;
	else if (nbr == 0)
		return (1);
	else
		nbr = -nbr;
	while (nbr < 0)
	{
		nbr /= 10;
		int_len++;
	}
	return (int_len);
}
