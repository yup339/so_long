/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:37:24 by pbergero          #+#    #+#             */
/*   Updated: 2023/01/15 12:03:11 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	size;
	size_t	i;

	size = ft_strlen(s);
	i = 0;
	if (start > size)
		return (ft_strdup(""));
	while (s[start + i] && i < len)
		i++;
	str = ft_calloc(i + 1, 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, &s[start], i + 1);
	return (str);
}
