/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_texture2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:34:25 by pbergero          #+#    #+#             */
/*   Updated: 2023/01/31 16:05:28 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/sprites.h"

void	get_attack_sprites(t_game *game)
{
	int			x;
	int			y;
	t_sprite	*temp;

	game->player->attack = malloc(sizeof(t_sprite));
	temp = game->player->attack;
	game->player->attack->sprite
		= mlx_xpm_file_to_image(game->mlx, ATTACK1, &x, &y);
	game->player->attack->next_frame = malloc(sizeof(t_sprite));
	game->player->attack = game->player->attack->next_frame;
	game->player->attack->sprite
		= mlx_xpm_file_to_image(game->mlx, ATTACK2, &x, &y);
	game->player->attack->next_frame = malloc(sizeof(t_sprite));
	game->player->attack = game->player->attack->next_frame;
	game->player->attack->sprite
		= mlx_xpm_file_to_image(game->mlx, ATTACK3, &x, &y);
	game->player->attack->next_frame = temp;
}

void	get_reverse_attack_sprites(t_game *game)
{
	int			x;
	int			y;
	t_sprite	*temp;

	game->player->r_attack = malloc(sizeof(t_sprite));
	temp = game->player->r_attack;
	game->player->r_attack->sprite
		= mlx_xpm_file_to_image(game->mlx, R_ATTACK1, &x, &y);
	game->player->r_attack->next_frame = malloc(sizeof(t_sprite));
	game->player->r_attack = game->player->r_attack->next_frame;
	game->player->r_attack->sprite
		= mlx_xpm_file_to_image(game->mlx, R_ATTACK2, &x, &y);
	game->player->r_attack->next_frame = malloc(sizeof(t_sprite));
	game->player->r_attack = game->player->r_attack->next_frame;
	game->player->r_attack->sprite
		= mlx_xpm_file_to_image(game->mlx, R_ATTACK3, &x, &y);
	game->player->r_attack->next_frame = temp;
}

void	get_dying_texture(t_game *game)
{
	int			x;
	int			y;
	t_sprite	*temp;

	game->player->dead = malloc(sizeof(t_sprite));
	temp = game->player->dead;
	game->player->dead->sprite
		= mlx_xpm_file_to_image(game->mlx, DEAD2, &x, &y);
	game->player->dead->next_frame = malloc(sizeof(t_sprite));
	game->player->dead = game->player->dead->next_frame;
	game->player->dead->sprite
		= mlx_xpm_file_to_image(game->mlx, DEAD3, &x, &y);
	game->player->dead->next_frame = malloc(sizeof(t_sprite));
	game->player->dead = game->player->dead->next_frame;
	game->player->dead->sprite
		= mlx_xpm_file_to_image(game->mlx, DEAD1, &x, &y);
	game->player->dead->next_frame = temp;
}

void	get_reverse_dying_texture(t_game *game)
{
	int			x;
	int			y;
	t_sprite	*temp;

	game->player->r_dead = malloc(sizeof(t_sprite));
	temp = game->player->r_dead;
	game->player->r_dead->sprite
		= mlx_xpm_file_to_image(game->mlx, R_DEAD2, &x, &y);
	game->player->r_dead->next_frame = malloc(sizeof(t_sprite));
	game->player->r_dead = game->player->r_dead->next_frame;
	game->player->r_dead->sprite
		= mlx_xpm_file_to_image(game->mlx, R_DEAD3, &x, &y);
	game->player->r_dead->next_frame = malloc(sizeof(t_sprite));
	game->player->r_dead = game->player->r_dead->next_frame;
	game->player->r_dead->sprite
		= mlx_xpm_file_to_image(game->mlx, R_DEAD1, &x, &y);
	game->player->r_dead->next_frame = temp;
}
