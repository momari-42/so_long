/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:30:02 by momari            #+#    #+#             */
/*   Updated: 2023/11/14 01:51:45 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwords(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || !s[i + 1]))
			count++;
		i++;
	}
	return (count);
}

static char	**ft_free(char **newstr, int j)
{
	while (j)
	{
		free(newstr[j - 1]);
		j--;
	}
	free(newstr);
	return (NULL);
}

static char	**ft_fillwords(char **newstr, const char *s, char c)
{
	unsigned int	i;
	unsigned int	j;
	size_t			len;

	i = 0;
	j = 0;
	while (s[i])
	{
		len = 0;
		while (s[i] == c && s[i])
			i++;
		while (s[i + len] != c && s[i + len])
			len++;
		if (len > 0)
		{
			newstr[j] = ft_substr(s, i, len);
			if (!newstr[j])
				return (ft_free(newstr, j));
			j++;
		}
		i += len;
	}
	return (newstr);
}

char	**ft_split(char const *s, char c)
{
	char	**newstr;
	int		lenwords;

	if (!s)
		return (NULL);
	lenwords = ft_countwords(s, c);
	newstr = (char **)malloc((lenwords + 1) * sizeof(char *));
	if (!newstr)
		return (NULL);
	newstr[lenwords] = 0;
	newstr = ft_fillwords(newstr, s, c);
	return (newstr);
}
