/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:39:30 by pbergero          #+#    #+#             */
/*   Updated: 2023/01/15 12:01:37 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static char	*getnsize(int n)
{
	int		digit;
	long	nbr;
	char	*nb;

	digit = 1;
	nbr = n;
	if (n < 0)
	{
		digit++;
		nbr = -nbr;
	}
	while (nbr >= 10)
	{
		digit ++;
		nbr = nbr / 10;
	}
	nb = malloc(digit + 1);
	if (!nb)
		return (NULL);
	return (nb);
}

static int	getlen(long n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		len++;
		n = n * -1;
	}
	while (n >= 10)
	{
		len++;
		n /= 10;
	}	
	return (len);
}

char	*ft_itoa(int n)
{
	char	*nbr;
	long	nb;
	int		len;
	int		i;

	nb = n;
	nbr = getnsize(n);
	i = 0;
	if (!nbr)
		return (NULL);
	len = getlen(nb);
	nbr[len] = 0;
	if (n < 0)
	{
		nbr[i++] = '-';
		nb = -nb;
	}
	while (len-- > i)
	{
		nbr[len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (nbr);
}
