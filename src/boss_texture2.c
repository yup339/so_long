/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boss_texture2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 02:23:02 by pbergero          #+#    #+#             */
/*   Updated: 2023/01/25 02:46:57 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/sprites.h"

static void	get_boss_death_sprite3(t_game *game, int x, int y)
{
	game->boss[0]->death->next_frame = malloc(sizeof(t_sprite));
	game->boss[0]->death = game->boss[0]->death->next_frame;
	game->boss[0]->death->sprite
		= mlx_xpm_file_to_image(game->mlx, BOSS_DEATH8, &x, &y);
	game->boss[0]->death->next_frame = malloc(sizeof(t_sprite));
	game->boss[0]->death = game->boss[0]->death->next_frame;
	game->boss[0]->death->sprite
		= mlx_xpm_file_to_image(game->mlx, BOSS_DEATH9, &x, &y);
	game->boss[0]->death->next_frame = malloc(sizeof(t_sprite));
	game->boss[0]->death = game->boss[0]->death->next_frame;
	game->boss[0]->death->sprite
		= mlx_xpm_file_to_image(game->mlx, BOSS_DEATH10, &x, &y);
	game->boss[0]->death->next_frame = malloc(sizeof(t_sprite));
	game->boss[0]->death = game->boss[0]->death->next_frame;
	game->boss[0]->death->sprite
		= mlx_xpm_file_to_image(game->mlx, BOSS_DEATH11, &x, &y);
}

void	get_boss_death_sprite2(t_game *game, int x, int y)
{
	game->boss[0]->death->next_frame = malloc(sizeof(t_sprite));
	game->boss[0]->death = game->boss[0]->death->next_frame;
	game->boss[0]->death->sprite
		= mlx_xpm_file_to_image(game->mlx, BOSS_DEATH5, &x, &y);
	game->boss[0]->death->next_frame = malloc(sizeof(t_sprite));
	game->boss[0]->death = game->boss[0]->death->next_frame;
	game->boss[0]->death->sprite
		= mlx_xpm_file_to_image(game->mlx, BOSS_DEATH6, &x, &y);
	game->boss[0]->death->next_frame = malloc(sizeof(t_sprite));
	game->boss[0]->death = game->boss[0]->death->next_frame;
	game->boss[0]->death->sprite
		= mlx_xpm_file_to_image(game->mlx, BOSS_DEATH7, &x, &y);
	get_boss_death_sprite3(game, x, y);
}

void	get_boss_idle_sprite2(t_game *game, int x, int y)
{
	game->boss[0]->idle->next_frame = malloc(sizeof(t_sprite));
	game->boss[0]->idle = game->boss[0]->idle->next_frame;
	game->boss[0]->idle->sprite
		= mlx_xpm_file_to_image(game->mlx, BOSS_IDLE4, &x, &y);
	game->boss[0]->idle->next_frame = malloc(sizeof(t_sprite));
	game->boss[0]->idle = game->boss[0]->idle->next_frame;
	game->boss[0]->idle->sprite
		= mlx_xpm_file_to_image(game->mlx, BOSS_IDLE5, &x, &y);
	game->boss[0]->idle->next_frame = malloc(sizeof(t_sprite));
	game->boss[0]->idle = game->boss[0]->idle->next_frame;
	game->boss[0]->idle->sprite
		= mlx_xpm_file_to_image(game->mlx, BOSS_IDLE6, &x, &y);
}

void	get_boss_attack_sprite2(t_game *game, int x, int y)
{
	game->boss[0]->attack->next_frame = malloc(sizeof(t_sprite));
	game->boss[0]->attack = game->boss[0]->attack->next_frame;
	game->boss[0]->attack->sprite
		= mlx_xpm_file_to_image(game->mlx, BOSS_ATTACK5, &x, &y);
	game->boss[0]->attack->next_frame = malloc(sizeof(t_sprite));
	game->boss[0]->attack = game->boss[0]->attack->next_frame;
	game->boss[0]->attack->sprite
		= mlx_xpm_file_to_image(game->mlx, BOSS_ATTACK6, &x, &y);
	game->boss[0]->attack->next_frame = malloc(sizeof(t_sprite));
	game->boss[0]->attack = game->boss[0]->attack->next_frame;
	game->boss[0]->attack->sprite
		= mlx_xpm_file_to_image(game->mlx, BOSS_ATTACK7, &x, &y);
	game->boss[0]->attack->next_frame = malloc(sizeof(t_sprite));
	game->boss[0]->attack = game->boss[0]->attack->next_frame;
	game->boss[0]->attack->sprite
		= mlx_xpm_file_to_image(game->mlx, BOSS_ATTACK8, &x, &y);
}
