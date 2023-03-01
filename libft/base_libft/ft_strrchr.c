/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:32:32 by pbergero          #+#    #+#             */
/*   Updated: 2023/01/15 12:03:05 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		i;
	int		n;

	i = 0;
	n = 0;
	str = (char *)s;
	if (!s)
		return (NULL);
	while (s[i])
	{
		str++;
		i++;
	}
	while (n++ <= i)
	{
		if (*str-- == (char)c)
			return (++str);
	}
	return (0);
}
