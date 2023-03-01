/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   golem_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 05:16:52 by pbergero          #+#    #+#             */
/*   Updated: 2023/01/25 09:31:26 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/sprites.h"

static void	get_golem_death_sprite(t_game *game)
{
	int			x;
	int			y;
	t_sprite	*temp;

	game->golem[0]->death = malloc(sizeof(t_sprite));
	temp = game->golem[0]->death;
	game->golem[0]->death->sprite
		= mlx_xpm_file_to_image(game->mlx, GOLEM_DEATH1, &x, &y);
	game->golem[0]->death->next_frame = malloc(sizeof(t_sprite));
	game->golem[0]->death = game->golem[0]->death->next_frame;
	game->golem[0]->death->sprite
		= mlx_xpm_file_to_image(game->mlx, GOLEM_DEATH2, &x, &y);
	game->golem[0]->death->next_frame = malloc(sizeof(t_sprite));
	game->golem[0]->death = game->golem[0]->death->next_frame;
	game->golem[0]->death->sprite
		= mlx_xpm_file_to_image(game->mlx, GOLEM_DEATH3, &x, &y);
	game->golem[0]->death->next_frame = malloc(sizeof(t_sprite));
	game->golem[0]->death = game->golem[0]->death->next_frame;
	game->golem[0]->death->sprite
		= mlx_xpm_file_to_image(game->mlx, GOLEM_DEATH4, &x, &y);
	game->golem[0]->death->next_frame = malloc(sizeof(t_sprite));
	game->golem[0]->death = game->golem[0]->death->next_frame;
	game->golem[0]->death->sprite
		= mlx_xpm_file_to_image(game->mlx, GOLEM_DEATH5, &x, &y);
	game->golem[0]->death->next_frame = temp;
}

static void	get_golem_hit_sprite(t_game *game)
{
	int			x;
	int			y;
	t_sprite	*temp;

	game->golem[0]->hit = malloc(sizeof(t_sprite));
	temp = game->golem[0]->hit;
	game->golem[0]->hit->sprite
		= mlx_xpm_file_to_image(game->mlx, GOLEM_HIT1, &x, &y);
	game->golem[0]->hit->next_frame = malloc(sizeof(t_sprite));
	game->golem[0]->hit = game->golem[0]->hit->next_frame;
	game->golem[0]->hit->sprite
		= mlx_xpm_file_to_image(game->mlx, GOLEM_HIT2, &x, &y);
	game->golem[0]->hit->next_frame = malloc(sizeof(t_sprite));
	game->golem[0]->hit = game->golem[0]->hit->next_frame;
	game->golem[0]->hit->sprite
		= mlx_xpm_file_to_image(game->mlx, GOLEM_HIT3, &x, &y);
	game->golem[0]->hit->next_frame = malloc(sizeof(t_sprite));
	game->golem[0]->hit = game->golem[0]->hit->next_frame;
	game->golem[0]->hit->sprite
		= mlx_xpm_file_to_image(game->mlx, GOLEM_HIT4, &x, &y);
	game->golem[0]->hit->next_frame = temp;
}

static void	get_golem_attack_sprite(t_game *game)
{
	int			x;
	int			y;
	t_sprite	*temp;

	game->golem[0]->attack = malloc(sizeof(t_sprite));
	temp = game->golem[0]->attack;
	game->golem[0]->attack->sprite
		= mlx_xpm_file_to_image(game->mlx, GOLEM_ATTACK1, &x, &y);
	game->golem[0]->attack->next_frame = malloc(sizeof(t_sprite));
	game->golem[0]->attack = game->golem[0]->attack->next_frame;
	game->golem[0]->attack->sprite
		= mlx_xpm_file_to_image(game->mlx, GOLEM_ATTACK2, &x, &y);
	game->golem[0]->attack->next_frame = malloc(sizeof(t_sprite));
	game->golem[0]->attack = game->golem[0]->attack->next_frame;
	game->golem[0]->attack->sprite
		= mlx_xpm_file_to_image(game->mlx, GOLEM_ATTACK3, &x, &y);
	game->golem[0]->attack->next_frame = malloc(sizeof(t_sprite));
	game->golem[0]->attack = game->golem[0]->attack->next_frame;
	game->golem[0]->attack->sprite
		= mlx_xpm_file_to_image(game->mlx, GOLEM_ATTACK4, &x, &y);
	game->golem[0]->attack->next_frame = temp;
	game->golem[0]->attack = game->golem[0]->attack->next_frame;
}

static void	get_golem_reverse_attack_sprite(t_game *game)
{
	int			x;
	int			y;
	t_sprite	*temp;

	game->golem[0]->r_attack = malloc(sizeof(t_sprite));
	temp = game->golem[0]->r_attack;
	game->golem[0]->r_attack->sprite
		= mlx_xpm_file_to_image(game->mlx, GOLEM_R_ATTACK1, &x, &y);
	game->golem[0]->r_attack->next_frame = malloc(sizeof(t_sprite));
	game->golem[0]->r_attack = game->golem[0]->r_attack->next_frame;
	game->golem[0]->r_attack->sprite
		= mlx_xpm_file_to_image(game->mlx, GOLEM_R_ATTACK2, &x, &y);
	game->golem[0]->r_attack->next_frame = malloc(sizeof(t_sprite));
	game->golem[0]->r_attack = game->golem[0]->r_attack->next_frame;
	game->golem[0]->r_attack->sprite
		= mlx_xpm_file_to_image(game->mlx, GOLEM_R_ATTACK3, &x, &y);
	game->golem[0]->r_attack->next_frame = malloc(sizeof(t_sprite));
	game->golem[0]->r_attack = game->golem[0]->r_attack->next_frame;
	game->golem[0]->r_attack->sprite
		= mlx_xpm_file_to_image(game->mlx, GOLEM_R_ATTACK4, &x, &y);
	game->golem[0]->r_attack->next_frame = temp;
	game->golem[0]->r_attack = game->golem[0]->r_attack->next_frame;
}

void	get_golem_texture(t_game *game)
{
	int	i;

	i = 1;
	get_golem_idle_sprite(game);
	get_golem_death_sprite(game);
	get_golem_attack_sprite(game);
	get_golem_reverse_attack_sprite(game);
	get_golem_hit_sprite(game);
	while (i < game->nb_golem)
	{
		game->golem[i]->idle = game->golem[0]->idle;
		game->golem[i]->attack = game->golem[0]->attack;
		game->golem[i]->death = game->golem[0]->death;
		game->golem[i]->hit = game->golem[0]->hit;
		game->golem[i]->r_attack = game->golem[0]->r_attack;
		i++;
	}
}
