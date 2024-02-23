/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 18:11:13 by momari            #+#    #+#             */
/*   Updated: 2023/11/18 22:46:46 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_long(long n, int *count)
{
	if (n < 0)
	{
		ft_putchar('-', count);
		ft_putnbr_long(-n, count);
	}
	else if (n < 10)
		ft_putchar(n + '0', count);
	else
	{
		ft_putnbr_long(n / 10, count);
		ft_putnbr_long(n % 10, count);
	}
}

void	ft_putnbr(int n, int *count)
{
	long	l;

	l = (long)n;
	ft_putnbr_long(l, count);
}
