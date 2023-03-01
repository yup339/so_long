/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 19:08:54 by pbergero          #+#    #+#             */
/*   Updated: 2023/02/11 09:50:05 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/flood_fill.h"
#include "../libft/include/libft.h"

int	flood(char **map, int y, int x, int coll)
{
	static int	nb_coll = -1;

	if (nb_coll == -1)
		nb_coll = coll + 1;
	if (map[y][x] == '1')
		return (nb_coll);
	if (map[y][x] == 'C' || map[y][x] == 'E' || map[y][x] == 'b')
	nb_coll--;
	map[y][x] = '1';
	flood(map, y + 1, x, nb_coll);
	flood(map, y, x + 1, nb_coll);
	flood(map, y - 1, x, nb_coll);
	flood(map, y, x - 1, nb_coll);
	return (nb_coll);
}

int	flood_fill(char **map, int nb_coll)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				if (flood(map, y, x, nb_coll))
				{
					printf("ERROR: your map cannot be completed");
					free_double_array((void **)map);
					return (0);
				}
			}
			x++;
		}
		y++;
	}
	free_double_array((void **)map);
	return (1);
}
