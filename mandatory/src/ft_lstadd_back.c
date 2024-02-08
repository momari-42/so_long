/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 08:25:55 by momari            #+#    #+#             */
/*   Updated: 2024/02/04 08:34:14 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

// void	ft_lstadd_back_data(t_datamap **lst, t_datamap *new)
// {
// 	t_datamap	*current;

// 	if (lst == NULL || new == NULL)
// 		return ;
// 	if (*lst == NULL)
// 	{
// 		*lst = new;
// 		return ;
// 	}
// 	current = *lst;
// 	while (current->next != NULL)
// 	{
// 		current = current->next;
// 	}
// 	current->next = new;
// }


void	ft_lstadd_back(char **map, char *line, int n)
{
	if (map == NULL || line == NULL)
		return ;
	map[n] = ft_strdup(line);
}
