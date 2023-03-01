/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_animation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:21:49 by pbergero          #+#    #+#             */
/*   Updated: 2023/02/19 20:14:12 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	print_run_animation(t_game *game)
{
	if (game->player->direction == RIGHT)
	{
		if (game->animation_state % 5 == 0)
			game->player->run = game->player->run->next_frame;
		mlx_put_image_to_window(game->mlx, game->window,
			game->player->run->sprite, game->player->x, game->player->y);
	}
	else
	{
		if (game->animation_state % 5 == 0)
			game->player->r_run = game->player->r_run->next_frame;
		mlx_put_image_to_window(game->mlx, game->window,
			game->player->r_run->sprite, game->player->x, game->player->y);
	}
}

void	print_idle_animation(t_game *game)
{
	if (game->player->direction == RIGHT)
	{
		if (game->animation_state % 8 == 0)
			game->player->idle = game->player->idle->next_frame;
		mlx_put_image_to_window(game->mlx, game->window,
			game->player->idle->sprite, game->player->x, game->player->y);
	}
	else
	{
		if (game->animation_state % 8 == 0)
			game->player->r_idle = game->player->r_idle->next_frame;
		mlx_put_image_to_window(game->mlx, game->window,
			game->player->r_idle->sprite, game->player->x, game->player->y);
	}
}

void	print_attack_animation(t_game *game)
{
	if (game->player->direction == RIGHT)
	{
		if (game->animation_state % 2)
			game->player->attack = game->player->attack->next_frame;
		mlx_put_image_to_window(game->mlx, game->window,
			game->player->attack->sprite, game->player->x, game->player->y);
	}
	else
	{
		if (game->animation_state % 2)
			game->player->r_attack = game->player->r_attack->next_frame;
		mlx_put_image_to_window(game->mlx, game->window,
			game->player->r_attack->sprite, game->player->x, game->player->y);
	}
}

void	print_dying_animation(t_game *game)
{
	if (game->player->direction == RIGHT)
	{
		if (game->animation_state % 40 == 0 && game->player->dying_state)
		{
			game->player->dead = game->player->dead->next_frame;
			game->player->dying_state--;
		}
		mlx_put_image_to_window(game->mlx, game->window,
			game->player->dead->sprite, game->player->x, game->player->y);
	}
	else
	{
		if (game->animation_state % 40 == 0 && game->player->dying_state)
		{
			game->player->r_dead = game->player->r_dead->next_frame;
			game->player->dying_state--;
		}
		mlx_put_image_to_window(game->mlx, game->window,
			game->player->r_dead->sprite, game->player->x, game->player->y);
	}
}
