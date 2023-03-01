/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:34:06 by pbergero          #+#    #+#             */
/*   Updated: 2023/01/15 12:02:43 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;

	if (!s)
		return (NULL);
	ptr = malloc(ft_strlen(s) + 1 * sizeof(char));
	if (!ptr || !s)
		return (ptr);
	ft_strlcpy(ptr, s, ft_strlen(s) + 1);
	return (ptr);
}
