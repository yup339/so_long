/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:34:03 by pbergero          #+#    #+#             */
/*   Updated: 2023/01/15 12:02:40 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	int		i;
	int		n;

	i = 0;
	n = 0;
	str = (char *)s;
	if (!str)
		return (NULL);
	while (s[i])
		i++;
	while (n++ <= i)
		if (*str++ == (char)c)
			return (--str);
	return (0);
}
