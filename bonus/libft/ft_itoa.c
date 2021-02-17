/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonig <lkonig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 20:57:39 by lkonig            #+#    #+#             */
/*   Updated: 2020/05/06 10:35:27 by lkonig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*zero(void)
{
	char	*res;

	res = "0";
	res = ft_strdup(res);
	return (res);
}

static void	*ft_memalloc(size_t size)
{
	char *str;

	str = (char *)malloc(sizeof(char) * size);
	if (str == NULL)
		return (NULL);
	ft_bzero(str, size);
	return (str);
}

char		*ft_itoa(int n)
{
	char			*s;
	unsigned int	k;
	size_t			len;

	if (n == 0)
		return (zero());
	k = (n < 0) ? -n : n;
	len = (n < 0) ? 1 : 0;
	while (k > 0)
	{
		k = k / 10;
		len++;
	}
	if (!(s = ft_memalloc(sizeof(char) * len + 1)))
		return (NULL);
	k = (n < 0) ? -n : n;
	while (k > 0)
	{
		len -= 1;
		s[len] = (k % 10) + 48;
		k = k / 10;
	}
	if (n < 0)
		s[0] = '-';
	return (s);
}
