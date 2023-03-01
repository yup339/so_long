/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 21:34:35 by pbergero          #+#    #+#             */
/*   Updated: 2023/01/15 12:01:43 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*nextone;

	nextone = *lst;
	while (nextone)
	{
		nextone = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = nextone;
	}
}
