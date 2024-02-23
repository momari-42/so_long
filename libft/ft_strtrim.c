/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 23:45:39 by momari            #+#    #+#             */
/*   Updated: 2023/11/14 02:59:26 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strsearsh(char const *s1, const char b)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] == b)
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		s1_len;
	char	*ptr;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[i] && ft_strsearsh(set, s1[i]) == 0)
		i++;
	s1_len = ft_strlen(s1) - 1;
	while (s1[s1_len] && ft_strsearsh(set, s1[s1_len]) == 0)
		s1_len--;
	s1_len++;
	if (i > s1_len)
		return (ft_strdup(""));
	ptr = (char *)malloc((s1_len - i) + 1);
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, s1 + i, s1_len - i + 1);
	return (ptr);
}
