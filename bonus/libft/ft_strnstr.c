/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonig <lkonig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 22:57:17 by lkonig            #+#    #+#             */
/*   Updated: 2020/04/28 22:57:19 by lkonig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	if (!(*s2))
		return ((char *)s1);
	i = 0;
	while (s1[i] != '\0' && i < len)
	{
		if (s1[i] == s2[0])
		{
			j = i;
			k = 0;
			while (j < len && s1[j] == s2[k] && s2[k] != '\0')
			{
				if (s2[k + 1] == '\0')
					return ((char *)s1 + i);
				j++;
				k++;
			}
		}
		i++;
	}
	return (NULL);
}
