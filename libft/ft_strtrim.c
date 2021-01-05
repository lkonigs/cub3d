/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonig <lkonig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 17:29:24 by lkonig            #+#    #+#             */
/*   Updated: 2020/04/29 17:29:24 by lkonig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	inset(char const a, char const *set)
{
	size_t	isinset;
	size_t	j;

	isinset = 0;
	j = 0;
	while (set[j] != '\0')
	{
		if (a == set[j])
			isinset = 1;
		j++;
	}
	return (isinset);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	start;
	size_t	end;
	char	*s2;

	start = 0;
	end = ft_strlen(s1) - 1;
	while (inset(s1[start], set) == 1)
		start++;
	if (!s1[start])
		return (ft_substr(s1, 0, 0));
	while (inset(s1[end], set) == 1)
		end--;
	len = end - start + 2;
	if (!(s2 = (char *)malloc(sizeof(*s2) * len)))
		return (0);
	ft_strlcpy(s2, s1 + start, len);
	return (s2);
}
