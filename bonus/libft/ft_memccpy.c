/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonig <lkonig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 22:58:55 by lkonig            #+#    #+#             */
/*   Updated: 2020/04/28 22:58:56 by lkonig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*strd;
	const unsigned char	*strs;
	size_t				i;

	strd = (unsigned char *)dest;
	strs = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		*strd = *strs;
		dest++;
		if (*strs == (unsigned char)c)
			return (dest);
		i++;
		strd++;
		strs++;
	}
	return (NULL);
}
