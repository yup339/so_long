/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:50:26 by pbergero          #+#    #+#             */
/*   Updated: 2023/01/15 14:19:59 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../include/libft.h"

char	*ft_strjoin_gnl(char *str, char *buf)
{
	char	*s;
	int		i;
	int		j;

	s = ft_calloc(ft_strlen(str) + ft_strlen(buf) + 1, 1);
	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	while (str && str[i])
	{
		s[i] = str[i];
		i++;
	}
	while (buf && buf[j])
	{
		s[i + j] = buf[j];
		j++;
	}
	s[i + j] = '\0';
	str = cleanit(str);
	return (s);
}

int	ft_strchr_gnl(const char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			return (c);
		i++;
	}
	return (0);
}
