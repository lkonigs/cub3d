/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonig <lkonig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 22:57:40 by lkonig            #+#    #+#             */
/*   Updated: 2020/05/07 11:17:20 by lkonig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*strd;
	const char	*strs;
	size_t		i;

	strd = (char *)dest;
	strs = (const char *)src;
	i = 0;
	if (!n || dest == src)
		return (dest);
	while (i < n)
	{
		strd[i] = strs[i];
		i++;
	}
	return (dest);
}
