/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:36:57 by pbergero          #+#    #+#             */
/*   Updated: 2023/01/25 02:54:59 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/sprites.h"

static void	get_coll_sprite(t_game *game)
{
	int			x;
	int			y;
	t_sprite	*temp;

	game->coll = malloc(sizeof(t_sprite));
	temp = game->coll;
	game->coll->sprite
		= mlx_xpm_file_to_image(game->mlx, COLL1, &x, &y);
	game->coll->next_frame = malloc(sizeof(t_sprite));
	game->coll = game->coll->next_frame;
	game->coll->sprite
		= mlx_xpm_file_to_image(game->mlx, COLL2, &x, &y);
	game->coll->next_frame = malloc(sizeof(t_sprite));
	game->coll = game->coll->next_frame;
	game->coll->sprite
		= mlx_xpm_file_to_image(game->mlx, COLL3, &x, &y);
	game->coll->next_frame = malloc(sizeof(t_sprite));
	game->coll = game->coll->next_frame;
	game->coll->sprite
		= mlx_xpm_file_to_image(game->mlx, COLL4, &x, &y);
	game->coll->next_frame = malloc(sizeof(t_sprite));
	game->coll = game->coll->next_frame;
	game->coll->sprite
		= mlx_xpm_file_to_image(game->mlx, COLL5, &x, &y);
	game->coll->next_frame = temp;
}

void	print_enemie(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->nb_enemie)
	{
		if (game->enemie[i]->status == ALIVE)
			print_mage(game, i);
		else
			print_dead_mage(game, i);
		i++;
	}
}

static void	get_door_sprite(t_game *game)
{
	int			x;
	int			y;
	t_sprite	*temp;

	game->exit = malloc(sizeof(t_sprite));
	temp = game->exit;
	game->exit->sprite
		= mlx_xpm_file_to_image(game->mlx, DOOR1, &x, &y);
	game->exit->next_frame = malloc(sizeof(t_sprite));
	game->exit = game->exit->next_frame;
	game->exit->sprite
		= mlx_xpm_file_to_image(game->mlx, DOOR2, &x, &y);
	game->exit->next_frame = malloc(sizeof(t_sprite));
	game->exit = game->exit->next_frame;
	game->exit->sprite
		= mlx_xpm_file_to_image(game->mlx, DOOR3, &x, &y);
	game->exit->next_frame = malloc(sizeof(t_sprite));
	game->exit = game->exit->next_frame;
	game->exit->sprite
		= mlx_xpm_file_to_image(game->mlx, DOOR4, &x, &y);
	game->exit->next_frame = temp;
}

void	get_tiles_sprites(t_game *game)
{
	get_coll_sprite(game);
	get_door_sprite(game);
}
