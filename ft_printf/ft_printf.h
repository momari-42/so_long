/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 23:05:04 by momari            #+#    #+#             */
/*   Updated: 2024/02/22 10:11:57 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
void	ft_putchar(int c, int *count);
void	ft_putstr(char *str, int *count);
void	ft_putnbr_h(unsigned int n, const char c, int *count);
void	ft_putnbr_a(unsigned long long n, int *count);
void	ft_putnbr(int n, int *count);
void	ft_putnbr_u(unsigned int n, int *count);

#endif
