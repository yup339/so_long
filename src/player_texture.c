/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:58:50 by pbergero          #+#    #+#             */
/*   Updated: 2023/01/17 16:16:57 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/sprites.h"

static void	get_idle_sprites(t_game *game)
{
	int			x;
	int			y;
	t_sprite	*temp;

	game->player->idle = malloc(sizeof(t_sprite));
	temp = game->player->idle;
	game->player->idle->sprite
		= mlx_xpm_file_to_image(game->mlx, PLAYER1, &x, &y);
	game->player->idle->next_frame = malloc(sizeof(t_sprite));
	game->player->idle = game->player->idle->next_frame;
	game->player->idle->sprite
		= mlx_xpm_file_to_image(game->mlx, PLAYER2, &x, &y);
	game->player->idle->next_frame = malloc(sizeof(t_sprite));
	game->player->idle = game->player->idle->next_frame;
	game->player->idle->sprite
		= mlx_xpm_file_to_image(game->mlx, PLAYER3, &x, &y);
	game->player->idle->next_frame = malloc(sizeof(t_sprite));
	game->player->idle = game->player->idle->next_frame;
	game->player->idle->sprite
		= mlx_xpm_file_to_image(game->mlx, PLAYER4, &x, &y);
	game->player->idle->next_frame = temp;
}

static void	get_reverse_idle_sprites(t_game *game)
{
	int			x;
	int			y;
	t_sprite	*temp;

	game->player->r_idle = malloc(sizeof(t_sprite));
	temp = game->player->r_idle;
	game->player->r_idle->sprite
		= mlx_xpm_file_to_image(game->mlx, R_PLAYER1, &x, &y);
	game->player->r_idle->next_frame = malloc(sizeof(t_sprite));
	game->player->r_idle = game->player->r_idle->next_frame;
	game->player->r_idle->sprite
		= mlx_xpm_file_to_image(game->mlx, R_PLAYER2, &x, &y);
	game->player->r_idle->next_frame = malloc(sizeof(t_sprite));
	game->player->r_idle = game->player->r_idle->next_frame;
	game->player->r_idle->sprite
		= mlx_xpm_file_to_image(game->mlx, R_PLAYER3, &x, &y);
	game->player->r_idle->next_frame = malloc(sizeof(t_sprite));
	game->player->r_idle = game->player->r_idle->next_frame;
	game->player->r_idle->sprite
		= mlx_xpm_file_to_image(game->mlx, R_PLAYER4, &x, &y);
	game->player->r_idle->next_frame = temp;
}

static void	get_running_sprites(t_game *game)
{
	int			x;
	int			y;
	t_sprite	*temp;

	game->player->run = malloc(sizeof(t_sprite));
	temp = game->player->run;
	game->player->run->sprite
		= mlx_xpm_file_to_image(game->mlx, RUN1, &x, &y);
	game->player->run->next_frame = malloc(sizeof(t_sprite));
	game->player->run = game->player->run->next_frame;
	game->player->run->sprite
		= mlx_xpm_file_to_image(game->mlx, RUN2, &x, &y);
	game->player->run->next_frame = malloc(sizeof(t_sprite));
	game->player->run = game->player->run->next_frame;
	game->player->run->sprite
		= mlx_xpm_file_to_image(game->mlx, RUN3, &x, &y);
	game->player->run->next_frame = malloc(sizeof(t_sprite));
	game->player->run = game->player->run->next_frame;
	game->player->run->sprite
		= mlx_xpm_file_to_image(game->mlx, RUN4, &x, &y);
	game->player->run->next_frame = temp;
}

static void	get_reverse_running_sprites(t_game *game)
{
	int			x;
	int			y;
	t_sprite	*temp;

	game->player->r_run = malloc(sizeof(t_sprite));
	temp = game->player->r_run;
	game->player->r_run->sprite
		= mlx_xpm_file_to_image(game->mlx, R_RUN1, &x, &y);
	game->player->r_run->next_frame = malloc(sizeof(t_sprite));
	game->player->r_run = game->player->r_run->next_frame;
	game->player->r_run->sprite
		= mlx_xpm_file_to_image(game->mlx, R_RUN2, &x, &y);
	game->player->r_run->next_frame = malloc(sizeof(t_sprite));
	game->player->r_run = game->player->r_run->next_frame;
	game->player->r_run->sprite
		= mlx_xpm_file_to_image(game->mlx, R_RUN3, &x, &y);
	game->player->r_run->next_frame = malloc(sizeof(t_sprite));
	game->player->r_run = game->player->r_run->next_frame;
	game->player->r_run->sprite
		= mlx_xpm_file_to_image(game->mlx, R_RUN4, &x, &y);
	game->player->r_run->next_frame = temp;
}

void	get_player_sprites(t_game *game)
{
	get_idle_sprites(game);
	get_reverse_idle_sprites(game);
	get_reverse_running_sprites(game);
	get_running_sprites(game);
	get_reverse_attack_sprites(game);
	get_attack_sprites(game);
	get_dying_texture(game);
	get_reverse_dying_texture(game);
}
