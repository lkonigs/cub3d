/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonig <lkonig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 22:52:49 by lkonig            #+#    #+#             */
/*   Updated: 2020/04/28 22:52:51 by lkonig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*strs;

	i = 0;
	strs = (unsigned char *)s;
	while (i++ < n)
	{
		if (*strs == (unsigned char)c)
			return ((void *)strs);
		strs++;
	}
	return (0);
}
