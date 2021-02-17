/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonig <lkonig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 17:32:25 by lkonig            #+#    #+#             */
/*   Updated: 2020/04/29 17:32:27 by lkonig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strjoin(char const *s1, char const *s2)
{
	size_t			len;
	size_t			i;
	size_t			j;
	size_t			k;
	char			*new;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	i = 0;
	if (!(new = malloc(sizeof(char) * len)))
		return (NULL);
	while (s1[i] != '\0' && i < len)
	{
		new[i] = s1[i];
		i++;
	}
	k = i;
	j = 0;
	while (s2[j] != '\0' && (k + j < len))
	{
		new[i] = s2[j];
		i++;
		j++;
	}
	new[i] = '\0';
	return (new);
}
