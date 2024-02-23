/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 21:15:21 by momari            #+#    #+#             */
/*   Updated: 2023/11/18 22:46:39 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_u(unsigned int n, int *count)
{
	if (n < 10)
		ft_putchar(n + '0', count);
	else
	{
		ft_putnbr_u(n / 10, count);
		ft_putnbr_u(n % 10, count);
	}
}
