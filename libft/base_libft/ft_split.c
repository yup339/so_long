/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:39:08 by pbergero          #+#    #+#             */
/*   Updated: 2023/01/15 12:02:37 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static char	**getgoodsize(const char *str, char c)
{
	char	**words;
	int		nbr_wrd;
	int		i;
	int		sw;

	nbr_wrd = 1;
	i = 0;
	sw = 0;
	while (str[i])
	{
		if (str[i] == c)
			sw = 0;
		if (str[i] != c)
		{
			if (sw == 0)
				nbr_wrd++;
			sw = 1;
		}
		i++;
	}
	words = (char **)malloc(nbr_wrd * (sizeof(char *)));
	if (!words)
		return (NULL);
	words[nbr_wrd - 1] = 0;
	return (words);
}

static int	getwordlength(char const *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i] && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

static char	**freeit(char	**words)
{
	int	i;

	i = 0;
	while (words[i])
	{
		free(words[i]);
		i++;
	}
	free(words);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**words;
	int		i;
	int		sw;
	int		wrdcount;
	char	*word;

	words = getgoodsize(s, c);
	if (!words || !s)
		return (NULL);
	i = -1;
	wrdcount = 0;
	sw = 0;
	while (s[++i])
	{
		if (s[i] == c)
			sw = 0;
		if (s[i] != c && sw++ == 0)
		{
			word = ft_substr(s, i, getwordlength(s, c, i));
			words[wrdcount++] = word;
			if (!word)
				return (freeit(words));
		}
	}
	return (words);
}
