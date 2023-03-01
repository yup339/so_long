/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_screen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:35:08 by pbergero          #+#    #+#             */
/*   Updated: 2023/02/25 16:29:24 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../libft/include/libft.h"

int	get_color(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	put_str_to_screen(t_game *game)
{
	if (game->str)
		free (game->str);
	game->str = ft_strjoin("MOVE COUNT = ", ft_itoa(game->move_count), 0, 1);
	mlx_string_put(game->mlx, game->window,
		((game->width / 2) * SPRITE_RES) - 100,
		(game->height * SPRITE_RES) + 30, get_color(255, 239, 182, 212),
		game->str);
}

int	print_error(char *msg, char **map)
{
	if (map)
		free_double_array((void **)map);
	printf("ERROR : %s\n", msg);
	return (0);
}
