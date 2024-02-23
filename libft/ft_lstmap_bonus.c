/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:35:41 by momari            #+#    #+#             */
/*   Updated: 2023/11/15 10:18:45 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*current;
	t_list	*newnode;

	if (!lst || !f || !del)
		return (NULL);
	newlist = NULL;
	current = lst;
	while (current)
	{
		newnode = ft_lstnew(NULL);
		if (!newnode)
		{
			ft_lstclear(&newlist, del);
			return (NULL);
		}
		newnode->content = f(current->content);
		ft_lstadd_back(&newlist, newnode);
		current = current->next;
	}
	return (newlist);
}
