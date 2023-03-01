/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boss_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:42:21 by pbergero          #+#    #+#             */
/*   Updated: 2023/01/30 17:15:15 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/sprites.h"

static void	get_boss_idle_sprite(t_game *game)
{
	int			x;
	int			y;
	t_sprite	*temp;

	game->boss[0]->idle = malloc(sizeof(t_sprite));
	temp = game->boss[0]->idle;
	game->boss[0]->idle->sprite
		= mlx_xpm_file_to_image(game->mlx, BOSS_IDLE1, &x, &y);
	game->boss[0]->idle->next_frame = malloc(sizeof(t_sprite));
	game->boss[0]->idle = game->boss[0]->idle->next_frame;
	game->boss[0]->idle->sprite
		= mlx_xpm_file_to_image(game->mlx, BOSS_IDLE2, &x, &y);
	game->boss[0]->idle->next_frame = malloc(sizeof(t_sprite));
	game->boss[0]->idle = game->boss[0]->idle->next_frame;
	game->boss[0]->idle->sprite
		= mlx_xpm_file_to_image(game->mlx, BOSS_IDLE3, &x, &y);
	get_boss_idle_sprite2(game, x, y);
	game->boss[0]->idle->next_frame = temp;
}

static void	get_boss_attack_sprite(t_game *game)
{
	int			x;
	int			y;
	t_sprite	*temp;

	game->boss[0]->attack = malloc(sizeof(t_sprite));
	temp = game->boss[0]->attack;
	game->boss[0]->attack->sprite
		= mlx_xpm_file_to_image(game->mlx, BOSS_ATTACK1, &x, &y);
	game->boss[0]->attack->next_frame = malloc(sizeof(t_sprite));
	game->boss[0]->attack = game->boss[0]->attack->next_frame;
	game->boss[0]->attack->sprite
		= mlx_xpm_file_to_image(game->mlx, BOSS_ATTACK2, &x, &y);
	game->boss[0]->attack->next_frame = malloc(sizeof(t_sprite));
	game->boss[0]->attack = game->boss[0]->attack->next_frame;
	game->boss[0]->attack->sprite
		= mlx_xpm_file_to_image(game->mlx, BOSS_ATTACK3, &x, &y);
	game->boss[0]->attack->next_frame = malloc(sizeof(t_sprite));
	game->boss[0]->attack = game->boss[0]->attack->next_frame;
	game->boss[0]->attack->sprite
		= mlx_xpm_file_to_image(game->mlx, BOSS_ATTACK4, &x, &y);
	get_boss_attack_sprite2(game, x, y);
	game->boss[0]->attack->next_frame = temp;
	game->boss[0]->death = game->boss[0]->death->next_frame;
}

static void	get_boss_death_sprite(t_game *game)
{
	int			x;
	int			y;
	t_sprite	*temp;

	game->boss[0]->death = malloc(sizeof(t_sprite));
	temp = game->boss[0]->death;
	game->boss[0]->death->sprite
		= mlx_xpm_file_to_image(game->mlx, BOSS_DEATH1, &x, &y);
	game->boss[0]->death->next_frame = malloc(sizeof(t_sprite));
	game->boss[0]->death = game->boss[0]->death->next_frame;
	game->boss[0]->death->sprite
		= mlx_xpm_file_to_image(game->mlx, BOSS_DEATH2, &x, &y);
	game->boss[0]->death->next_frame = malloc(sizeof(t_sprite));
	game->boss[0]->death = game->boss[0]->death->next_frame;
	game->boss[0]->death->sprite
		= mlx_xpm_file_to_image(game->mlx, BOSS_DEATH3, &x, &y);
	game->boss[0]->death->next_frame = malloc(sizeof(t_sprite));
	game->boss[0]->death = game->boss[0]->death->next_frame;
	game->boss[0]->death->sprite
		= mlx_xpm_file_to_image(game->mlx, BOSS_DEATH4, &x, &y);
	get_boss_death_sprite2(game, x, y);
	game->boss[0]->death->next_frame = temp;
	game->boss[0]->death = game->boss[0]->death->next_frame;
}

static void	get_boss_hit_sprite(t_game *game)
{
	int			x;
	int			y;
	t_sprite	*temp;

		game->boss[0]->hit = malloc(sizeof(t_sprite));
	temp = game->boss[0]->hit;
	game->boss[0]->hit->sprite
		= mlx_xpm_file_to_image(game->mlx, BOSS_TAKING_HIT2, &x, &y);
	game->boss[0]->hit->next_frame = malloc(sizeof(t_sprite));
	game->boss[0]->hit = game->boss[0]->hit->next_frame;
	game->boss[0]->hit->sprite
		= mlx_xpm_file_to_image(game->mlx, BOSS_TAKING_HIT3, &x, &y);
	game->boss[0]->hit->next_frame = malloc(sizeof(t_sprite));
	game->boss[0]->hit = game->boss[0]->hit->next_frame;
	game->boss[0]->hit->sprite
		= mlx_xpm_file_to_image(game->mlx, BOSS_TAKING_HIT4, &x, &y);
	game->boss[0]->hit->next_frame = malloc(sizeof(t_sprite));
	game->boss[0]->hit = game->boss[0]->hit->next_frame;
	game->boss[0]->hit->sprite
		= mlx_xpm_file_to_image(game->mlx, BOSS_TAKING_HIT5, &x, &y);
	game->boss[0]->hit->next_frame = malloc(sizeof(t_sprite));
	game->boss[0]->hit = game->boss[0]->hit->next_frame;
	game->boss[0]->hit->sprite
		= mlx_xpm_file_to_image(game->mlx, BOSS_TAKING_HIT1, &x, &y);
	game->boss[0]->hit->next_frame = temp;
}

void	get_boss_texture(t_game *game)
{
	int	i;

	i = 1;
	get_boss_idle_sprite(game);
	get_boss_death_sprite(game);
	get_boss_attack_sprite(game);
	get_boss_hit_sprite(game);
	while (i < game->nb_boss)
	{
		game->boss[i]->idle = game->boss[0]->idle;
		game->boss[i]->attack = game->boss[0]->attack;
		game->boss[i]->death = game->boss[0]->death;
		game->boss[i]->hit = game->boss[0]->hit;
		i++;
	}
}
