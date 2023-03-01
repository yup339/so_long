/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:38:41 by pbergero          #+#    #+#             */
/*   Updated: 2023/01/15 12:03:08 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len;
	char	*str;
	char	*start;

	start = (char *)s1;
	if (!s1 || !set)
		return (NULL);
	while (*start && ft_strchr(set, *start))
		start++;
	len = ft_strlen(start);
	while (ft_strchr(set, start[len]) && len != 0)
		len--;
	str = ft_substr(start, 0, len + 1);
	return (str);
}
