/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:34:09 by pbergero          #+#    #+#             */
/*   Updated: 2023/01/15 12:02:50 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	j;
	size_t	dlen;
	size_t	slen;

	if (!dst || !src)
		return (0);
	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	j = size;
	while (*dst)
	{
		dst++;
		if (j > 0)
			j--;
	}
	while (*src && j > 1)
	{
		*dst++ = *src++;
		j--;
	}
	*dst = 0;
	if (size > dlen)
		return (dlen + slen);
	return (slen + size);
}
