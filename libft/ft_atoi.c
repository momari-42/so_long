/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:38:25 by momari            #+#    #+#             */
/*   Updated: 2024/02/22 11:16:23 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_gameover(int sign)
{
	if (sign < 0)
		return (0);
	return (-1);
}

int	ft_atoi(const char *str)
{
	unsigned long	temp;
	long			pos;
	long			i;

	i = 0;
	temp = 0;
	pos = 1;
	while ((str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		|| (str[i] == '\f' || str[i] == '\r' || str[i] == '\v'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			pos *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((10 * temp) + (str[i] - '0') > 9223372036854775807)
			return (ft_gameover(pos));
		temp = (10 * temp) + (str[i] - '0');
		i++;
	}
	return (temp * pos);
}
