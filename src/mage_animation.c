/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mage_animation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:42:38 by pbergero          #+#    #+#             */
/*   Updated: 2023/01/27 16:48:14 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	print_mage(t_game *game, int i)
{
	if (game->enemie[i]->direction == RIGHT)
	{
		if (game->animation_state % 5 == 0)
			game->enemie[i]->run = game->enemie[i]->run->next_frame;
		mlx_put_image_to_window(game->mlx, game->window,
			game->enemie[i]->run->sprite,
			game->enemie[i]->x, game->enemie[i]->y);
	}
	else
	{
		if (game->animation_state % 5 == 0)
			game->enemie[i]->r_run = game->enemie[i]->r_run->next_frame;
		mlx_put_image_to_window(game->mlx, game->window,
			game->enemie[i]->r_run->sprite,
			game->enemie[i]->x, game->enemie[i]->y);
	}
}

void	print_dead_mage(t_game *game, int i)
{
	if (game->enemie[i]->direction == RIGHT)
	{
		if (game->animation_state % 20 == 0 && game->enemie[i]->dying_state)
		{
			game->enemie[i]->dying_state--;
			game->enemie[i]->dead = game->enemie[i]->dead->next_frame;
		}
		mlx_put_image_to_window(game->mlx, game->window,
			game->enemie[i]->dead->sprite,
			game->enemie[i]->x, game->enemie[i]->y);
	}
	else
	{
		if (game->animation_state % 20 == 0 && game->enemie[i]->dying_state)
		{
			game->enemie[i]->dying_state--;
			game->enemie[i]->r_dead = game->enemie[i]->r_dead->next_frame;
		}
		mlx_put_image_to_window(game->mlx, game->window,
			game->enemie[i]->r_dead->sprite,
			game->enemie[i]->x, game->enemie[i]->y);
	}
}

static int	check_barrel_collisions_left(t_game *game, int i)
{
	int	j;

	j = 0;
	if (game->nb_barrel)
	{
		while (j < game->nb_barrel)
		{
			if (game->barel[j]->x < game->enemie[i]->x + 50
				&& game->barel[j]->x + 75 > game->enemie[i]->x
				&& game->barel[j]->y < game->enemie[i]->y + 75
				&& game->barel[j]->y + 75 > game->enemie[i]->y
				&& game->barel[j]->state == ALIVE)
				return (1);
			j++;
		}
	}
	if (game->map[game->enemie[i]->y / 75]
		[(game->enemie[i]->x / 75)] == '1')
		return (1);
	return (0);
}

static int	check_barrel_collisions_right(t_game *game, int i)
{
	int	j;

	j = 0;
	if (game->nb_barrel)
	{
		while (j < game->nb_barrel)
		{
			if (game->barel[j]->x - 35 < game->enemie[i]->x + 50
				&& game->barel[j]->x > game->enemie[i]->x
				&& game->barel[j]->y < game->enemie[i]->y + 75
				&& game->barel[j]->y + 75 > game->enemie[i]->y
				&& game->barel[j]->state == ALIVE)
				return (1);
			j++;
		}
	}
	if (game->map[game->enemie[i]->y / 75]
		[(game->enemie[i]->x / 75) + 1] == '1')
		return (1);
	return (0);
}

void	move_mage(t_game *game)
{
	int	i;

	i = 0;
	while (game->nb_enemie > i)
	{
		if (game->enemie[i]->direction == RIGHT
			&& game->enemie[i]->status == ALIVE)
		{		
			if (check_barrel_collisions_right(game, i))
				game->enemie[i]->direction = LEFT;
			else
				game->enemie[i]->x += MAGE_SPEED;
		}
		else if (game->enemie[i]->direction == LEFT
			&& game->enemie[i]->status == ALIVE)
		{
			if (check_barrel_collisions_left(game, i))
				game->enemie[i]->direction = RIGHT;
			else
				game->enemie[i]->x -= MAGE_SPEED;
		}
		i++;
	}
}
