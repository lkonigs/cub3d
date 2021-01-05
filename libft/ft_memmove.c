/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonig <lkonig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 22:57:53 by lkonig            #+#    #+#             */
/*   Updated: 2020/05/07 10:58:30 by lkonig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*strd;
	const char	*strs;

	strd = (char *)dest;
	strs = (const char *)src;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (dest == src)
		return (dest);
	if (dest < src)
	{
		strd = ft_memcpy(dest, src, n);
	}
	else
	{
		while (n-- > 0)
			strd[n] = strs[n];
	}
	return (dest);
}
