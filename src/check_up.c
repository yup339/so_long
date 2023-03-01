/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 11:18:08 by pbergero          #+#    #+#             */
/*   Updated: 2023/02/26 14:38:38 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/libft.h"
#include "../include/so_long.h"

int	check_border_side(t_game *game)
{
	int	y;

	y = 0;
	game->height = 0;
	while (game->map[y])
	{
		if (game->map[y][0] != '1' || game->map[y][game->width - 1] != '1')
		{
			printf ("ERROR : map is not closed\n");
			return (0);
		}
		y++;
		game->height++;
	}
	return (1);
}

int	check_map_is_square(t_game *game)
{
	int	y;

	y = 0;
	game->height = 0;
	game->width = ft_strlen(game->map[0]);
	while (game->map[y])
	{
		if ((int)ft_strlen(game->map[y]) != game->width)
		{
			printf("ERROR : map is not square\n");
			return (0);
			game->height++;
		}
		y++;
	}
	return (1);
}

int	check_essential_char(t_game *game)
{
	if (get_nb_entity(game->str, 'P') != 1)
	{
		return (print_error("wrong number of Player", game->map));
	}
	if (get_nb_entity(game->str, 'E') != 1)
	{
		return (print_error("wrong number of Exit", game->map));
	}
	if (get_nb_entity(game->str, 'C') + get_nb_entity(game->str, 'b') == 0)
	{
		return (print_error("no collectable on the map", game->map));
	}
	if (game->width > 34 || game->height > 16)
		return (print_error("dimension too big for the game", game->map));
	return (1);
}

int	check_entity_space(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == 'D' || game->map[y][x] == 'G')
			{
				if (game->map[y + 1][x] == '1' || game->map[y + 1][x + 1] == '1'
					|| game->map[y][x + 1] == '1' || game->map[y + 1][x] == 'P'
					|| game->map[y + 1][x + 1] == 'P'
					|| game->map[y][x + 1] == 'P' || game->map[y + 1][x] == 'b'
					|| game->map[y + 1][x + 1] == 'b'
					|| game->map[y][x + 1] == 'b' || game->map[y + 1][x] == 'B'
					|| game->map[y + 1][x + 1] == 'B'
					|| game->map[y][x + 1] == 'B' )
					return (print_error("Demon/Golem dont have enough space"
							, game->map));
			}
		}
	}
	return (1);
}
