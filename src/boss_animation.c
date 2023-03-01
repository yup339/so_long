/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boss_animation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:06:46 by pbergero          #+#    #+#             */
/*   Updated: 2023/02/19 20:14:41 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/sprites.h"

static void	print_dead_boss(t_game *game, t_boss *boss)
{
	if (game->animation_state % 5 == 0 && boss->dying_state)
	{
		boss->death = boss->death->next_frame;
		boss->dying_state--;
	}
	mlx_put_image_to_window(game->mlx, game->window,
		boss->death->sprite, boss->x, boss->y);
}

static void	print_alive_boss(t_game *game, t_boss *boss)
{
	if (game->animation_state % 5 == 0)
		boss->idle = boss->idle->next_frame;
	mlx_put_image_to_window(game->mlx, game->window,
		boss->idle->sprite, boss->x, boss->y);
}

static void	print_attacking_boss(t_game *game, t_boss *boss)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (game->animation_state % 5 == 0)
	{
		boss->attack = boss->attack->next_frame;
		boss->attacking_state++;
	}
	if (boss->attacking_state == 6 || boss->attacking_state == 7
		|| boss->attacking_state == 8)
		x = -75;
	if (boss->attacking_state == 4 || boss->attacking_state == 5)
		y = -25;
	mlx_put_image_to_window(game->mlx, game->window,
		boss->attack->sprite, boss->x + x, boss->y + y);
	if (boss->attacking_state == 8)
	{
		boss->attacking_state = 1;
		boss->attack = boss->attack->next_frame;
		boss->status = ALIVE;
	}
}

static void	print_taking_hit_boss(t_game *game, t_boss *boss)
{
	if (game->animation_state % 5 == 0)
	{
		boss->hit = boss->hit->next_frame;
		boss->hit_state--;
	}
	mlx_put_image_to_window(game->mlx, game->window,
		boss->hit->sprite, boss->x, boss->y);
	if (!boss->hit_state)
	{
		boss->hit_state = 5;
		boss->hit = boss->hit->next_frame;
		boss->status = ALIVE;
	}
}

void	print_boss(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->nb_boss)
	{
		if (game->boss[i]->status == ALIVE)
			print_alive_boss(game, game->boss[i]);
		else if (game->boss[i]->status == DEAD)
			print_dead_boss(game, game->boss[i]);
		else if (game->boss[i]->status == ATTACK)
			print_attacking_boss(game, game->boss[i]);
		else if (game->boss[i]->status == TAKING_DAMAGE)
			print_taking_hit_boss(game, game->boss[i]);
		i++;
	}
}
