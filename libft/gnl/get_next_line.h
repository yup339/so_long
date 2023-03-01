/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:50:30 by pbergero          #+#    #+#             */
/*   Updated: 2023/01/15 13:32:01 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef  BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef  JUST_SOME_RANDOM_NUMBER_BECAUSE_NO_DOWHILE
#  define JUST_SOME_RANDOM_NUMBER_BECAUSE_NO_DOWHILE 69420
# endif

char	*get_next_line(int fd);
char	*ft_strjoin_gnl(char *str, char *buf);
int		ft_strchr_gnl(const char *s, char c);
void	*cleanit(char *ptr);
#endif