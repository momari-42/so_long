/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 10:22:27 by momari            #+#    #+#             */
/*   Updated: 2023/11/15 10:12:26 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	index;

	index = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			index = i;
		i++;
	}
	if (s[i] == (char)c)
		index = i;
	if (index || s[0] == (char)c)
		return ((char *)(s + index));
	return (0);
}
