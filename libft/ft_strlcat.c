/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonig <lkonig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 13:50:32 by lkonig            #+#    #+#             */
/*   Updated: 2020/05/02 13:50:34 by lkonig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dlen;
	size_t	toadd;
	char	*strd;
	char	*strs;

	strd = dest;
	strs = (char *)src;
	toadd = size;
	while (toadd-- > 0 && *strd != '\0')
		strd++;
	dlen = strd - dest;
	toadd = size - dlen;
	if (toadd == 0)
		return (dlen + ft_strlen(strs));
	while (*strs != '\0')
	{
		if (toadd >= 2)
		{
			*strd++ = *strs;
			toadd--;
		}
		strs++;
	}
	*strd = '\0';
	return (dlen + (strs - src));
}
