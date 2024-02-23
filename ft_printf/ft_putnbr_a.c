/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 11:22:09 by momari            #+#    #+#             */
/*   Updated: 2023/11/25 12:23:28 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_a(unsigned long long n, int *count)
{
	const char	*base;

	base = "0123456789abcdef";
	if (n < 16)
		ft_putchar(base[n], count);
	else
	{
		ft_putnbr_a(n / 16, count);
		ft_putnbr_a(n % 16, count);
	}
}
