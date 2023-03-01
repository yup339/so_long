/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:33:53 by pbergero          #+#    #+#             */
/*   Updated: 2023/01/15 12:02:01 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*s;

	if (!str)
		return (NULL);
	s = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		if (*s == (unsigned char)c)
			return (s);
		i++;
		s++;
	}
	return (0);
}
