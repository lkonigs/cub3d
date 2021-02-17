/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonig <lkonig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 17:33:17 by lkonig            #+#    #+#             */
/*   Updated: 2020/05/06 10:26:22 by lkonig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			nbwords(char const *s, char c)
{
	size_t	nbw;

	nbw = 0;
	while (*s)
	{
		if (*s != c)
		{
			if (*(s + 1) == c || *(s + 1) == '\0')
				nbw++;
		}
		s++;
	}
	return (nbw + 1);
}

static	void	*ft_memalloc(size_t size)
{
	char *str;

	str = (char *)malloc(sizeof(char) * size);
	if (str == NULL)
		return (NULL);
	ft_bzero(str, size);
	return (str);
}

char			**ft_split(char const *s, char c)
{
	char	**str;
	size_t	i;
	char	*res;

	if (!s || (!(str = (char **)ft_memalloc(sizeof(char *) * (nbwords(s, c))))))
		return (NULL);
	i = -1;
	while (*s)
	{
		while ((*s == c) && *s)
			++s;
		if (*s)
		{
			if (!(res = ft_strchr(s, c)))
				str[++i] = ft_substr(s, 0, ft_strlen(s));
			else
				str[++i] = ft_substr(s, 0, res - s);
		}
		while ((*s != c) && *s)
			s++;
	}
	return (str);
}
