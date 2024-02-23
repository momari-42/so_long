/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 08:24:18 by momari            #+#    #+#             */
/*   Updated: 2023/11/04 17:43:56 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		s1_len;

	s1_len = ft_strlen(s1);
	ptr = ft_calloc(s1_len + 1, sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ft_memcpy(ptr, s1, s1_len);
	return (ptr);
}
