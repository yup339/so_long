/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:50:28 by pbergero          #+#    #+#             */
/*   Updated: 2023/01/15 13:32:09 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../include/libft.h"

void	*cleanit(char *ptr)
{
	if (ptr)
		free(ptr);
	return (NULL);
}

static char	*trimit(char *str)
{
	int		size;
	char	*trim;
	int		i;

	i = 0;
	size = ft_strlen(str);
	trim = ft_calloc(size + 1, 1);
	if (!trim)
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
	{
		trim[i] = str[i];
		i++;
	}
	trim[i] = str[i];
	while (size > i++)
		trim[i] = 0;
	str = cleanit(str);
	return (trim);
}

static char	*find_next_line(char *buf, int fd)
{
	int		reading_result;
	char	*str;

	str = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!str)
		return (NULL);
	if (buf)
		str = ft_strjoin_gnl(str, buf);
	if (!str)
		return (NULL);
	reading_result = JUST_SOME_RANDOM_NUMBER_BECAUSE_NO_DOWHILE;
	while (reading_result > 0)
	{
		reading_result = read(fd, buf, BUFFER_SIZE);
		if (reading_result == -1)
			return (free(str), NULL);
		buf[reading_result] = 0;
		str = ft_strjoin_gnl(str, buf);
		if (ft_strchr(str, '\n') || !str)
			return (str);
	}
	if (str[0] != 0)
		return (str);
	str = cleanit(str);
	return (NULL);
}

static char	*update_buf(char *buf)
{
	char	*newbuf;
	int		i;
	int		j;

	j = 0;
	i = 0;
	newbuf = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!newbuf)
		return (NULL);
	while (buf[i] != '\n' && buf[i] != 0)
		i++;
	if (buf[i] == '\n')
		i++;
	while (buf[i + j] != 0)
	{
		newbuf[j] = buf[i + j];
		j++;
	}
	newbuf[j] = 0;
	buf = cleanit(buf);
	return (newbuf);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*str;

	if (!buf)
		buf = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!buf || fd < 0 || BUFFER_SIZE <= 0)
		return (buf = cleanit(buf));
	if (ft_strchr_gnl(buf, '\n') == '\n')
	{
		str = ft_calloc(1, 1);
		str = ft_strjoin_gnl(str, buf);
		buf = update_buf(buf);
		if (!buf || !str)
			return (buf = cleanit(buf));
		return (trimit(str));
	}
	str = find_next_line(buf, fd);
	if (!str)
		return (buf = cleanit(buf));
	buf = update_buf(buf);
	return (trimit(str));
}
