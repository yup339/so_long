/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:33:57 by pbergero          #+#    #+#             */
/*   Updated: 2023/01/15 12:02:15 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;
	size_t	i;

	i = -1;
	s = (char *)src;
	d = (char *)dest;
	if (!dest || !src)
		return (NULL);
	if (s > d)
	{
		while (++i < n)
		{
			d[i] = s[i];
		}
	}
	else
	{
		while (++i != n)
		{
			d[n - i - 1] = s[n - i - 1];
		}
	}
	return (dest);
}
