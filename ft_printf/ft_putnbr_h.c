/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_h.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 23:07:02 by momari            #+#    #+#             */
/*   Updated: 2023/11/18 22:55:10 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_h(unsigned int n, const char c, int *count)
{
	const char	*base;

	if (c == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n < 16)
		ft_putchar(base[n], count);
	else
	{
		ft_putnbr_h(n / 16, c, count);
		ft_putnbr_h(n % 16, c, count);
	}
}
