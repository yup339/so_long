/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 21:10:43 by pbergero          #+#    #+#             */
/*   Updated: 2023/01/15 12:00:11 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	iswhitespace(char c)
{
	if (c == 32 || c == '\f' || c == '\n'
		|| c == '\t' || c == '\v' || c == '\r')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	nbr;
	int	i;
	int	sign;

	if (!nptr)
		return (0);
	i = 0;
	nbr = 0;
	sign = 1;
	while (iswhitespace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nbr = (nbr * 10) + (nptr[i] - 48);
		i++;
	}
	return (nbr * sign);
}
