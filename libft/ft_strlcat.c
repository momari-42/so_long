/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 22:26:16 by momari            #+#    #+#             */
/*   Updated: 2023/11/14 02:21:52 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	d_len;
	size_t	s_len;

	i = 0;
	d_len = 0;
	if (!dst && !dstsize)
		return (ft_strlen(src));
	while (dst[d_len] && d_len < dstsize)
		d_len++;
	s_len = ft_strlen(src);
	if (dstsize == 0)
		return (s_len);
	j = d_len;
	if (dstsize > j && dstsize)
	{
		while (src[i] && j < dstsize - 1)
		{
			dst[j] = src[i++];
			j++;
		}
		dst[j] = '\0';
	}
	return (d_len + s_len);
}
