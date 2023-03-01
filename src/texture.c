/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:01:50 by pbergero          #+#    #+#             */
/*   Updated: 2023/01/29 17:34:49 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/sprites.h"

void	get_images(t_game *game)
{
	int			x;
	int			y;

	get_tiles_sprites(game);
	get_player_sprites(game);
	if (game->nb_enemie)
		get_enemie_texture(game);
	if (game->nb_barrel)
		get_barrel_sprite(game);
	if (game->nb_necro)
		get_necro_texture(game);
	if (game->nb_boss)
		get_boss_texture(game);
	if (game->nb_golem)
		get_golem_texture(game);
	game->grass
		= mlx_xpm_file_to_image(game->mlx, GRASS, &x, &y);
	game->wall
		= mlx_xpm_file_to_image(game->mlx, WALL, &x, &y);
}

void	print_cell(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->window, game->wall,
			x * SPRITE_RES, y * SPRITE_RES);
	else if (game->map[y][x] == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->window, game->coll->sprite,
			x * SPRITE_RES, y * SPRITE_RES);
	}
	else if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->window, game->exit->sprite,
			x * SPRITE_RES, y * SPRITE_RES);
}

void	print_player(t_game *game)
{
	if (game->player->status == ALIVE)
		print_idle_animation(game);
	else if (game->player->status == MOVING)
		print_run_animation(game);
	else if (game->player->status == ATTACK)
		print_attack_animation(game);
	else if (game->player->status == DEAD)
		print_dying_animation(game);
}

void	fill_floor(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->width)
	{
		y = 0;
		while (y < game->height)
		{
			mlx_put_image_to_window(game->mlx, game->window,
				game->grass, x * SPRITE_RES, y * SPRITE_RES);
			y++;
		}
		x++;
	}
}

void	print_map(t_game *game)
{
	int	x;
	int	y;

	if (game->animation_state % 6 == 0)
		game->coll = game->coll->next_frame;
	if (game->animation_state % 4 == 0 && game->nb_collectable == 0)
		game->exit = game->exit->next_frame;
	x = 0;
	fill_floor(game);
	if (game->nb_barrel)
		print_barrel(game);
	while (x < game->width)
	{
		y = 0;
		while (y < game->height)
		{
			print_cell(game, x, y);
			y++;
		}
		x++;
	}
	put_str_to_screen(game);
}
