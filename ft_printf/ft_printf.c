/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 09:24:54 by momari            #+#    #+#             */
/*   Updated: 2023/11/26 12:00:37 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_prints(va_list args, const char c, int *count)
{
	if (c == 'c')
		ft_putchar(va_arg(args, int), count);
	else if (c == 's')
		ft_putstr(va_arg(args, char *), count);
	else if (c == 'p')
	{
		ft_putstr("0x", count);
		ft_putnbr_a(va_arg(args, unsigned long long), count);
	}
	else if (c == 'd')
	{
		ft_putnbr(va_arg(args, int), count);
	}
	else if (c == 'i')
		ft_putnbr(va_arg(args, int), count);
	else if (c == 'u')
		ft_putnbr_u(va_arg(args, unsigned int), count);
	else if (c == 'x' || c == 'X')
		ft_putnbr_h(va_arg(args, unsigned long long), c, count);
	else if (c == '%')
		ft_putchar(c, count);
	else
		ft_putchar(c, count);
}

int	ft_printf(const char *str, ...)
{
	size_t	i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == '\0')
				break ;
			ft_prints(args, str[i], &count);
		}
		else
			ft_putchar(str[i], &count);
		i++;
	}
	va_end(args);
	return (count);
}
