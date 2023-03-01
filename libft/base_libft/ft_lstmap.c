/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 21:23:33 by pbergero          #+#    #+#             */
/*   Updated: 2023/01/15 12:01:55 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*newelem;

	if (!lst || !f)
		return (NULL);
	newlist = NULL;
	while (lst)
	{
		newelem = ft_lstnew((*f)(lst->content));
		if (!newelem)
		{
			ft_lstclear(&newlist, del);
			return (NULL);
		}
		ft_lstadd_back(&newlist, newelem);
		lst = lst->next;
	}
	ft_lstclear(&lst, del);
	return (newlist);
}
