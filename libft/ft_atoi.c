/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonig <lkonig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 09:59:43 by lkonig            #+#    #+#             */
/*   Updated: 2020/05/05 09:59:45 by lkonig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long long int	nb;
	int				flag;

	nb = 0;
	flag = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-')
		flag = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		nb = nb * 10 + *str - '0';
		if (flag == -1 && nb == 2147483648)
			return (-2147483648);
		if (flag == -1 && nb > 2147483647)
			return (0);
		if (flag == 1 && nb > 2147483647)
			return (-1);
		str++;
	}
	return (nb * flag);
}

int		ft_atoi_increment(const char *str, int *i)
{
	unsigned long	nb;
	int				flag;

	nb = 0;
	flag = 1;
	while (str[*i] && (str[*i] == ' ' || str[*i] == '\t' || str[*i] == '\n'
			|| str[*i] == '\r' || str[*i] == '\f' || str[*i] == '\v'))
		(*i)++;
	if (str[*i] == '-')
	{
		flag = -1;
		(*i)++;
	}
	else if (str[*i] == '+')
		(*i)++;
	while (str[*i] && str[*i] >= '0' && str[*i] <= '9')
	{
		nb *= 10;
		nb += str[*i] - 48;
		(*i)++;
	}
	return (nb * flag);
}
