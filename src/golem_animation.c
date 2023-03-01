/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   golem_animation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 05:17:01 by pbergero          #+#    #+#             */
/*   Updated: 2023/01/25 07:36:23 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	print_alive_golem(t_game *game, t_golem *golem)
{
	if (game->animation_state % 6 == 0)
		golem->idle = golem->idle->next_frame;
	mlx_put_image_to_window(game->mlx, game->window,
		golem->idle->sprite, golem->x, golem->y);
}

static void	print_dead_golem(t_game *game, t_golem *golem)
{
	if (game->animation_state % 9 == 0 && golem->dying_state)
	{
		golem->death = golem->death->next_frame;
		golem->dying_state--;
	}
	mlx_put_image_to_window(game->mlx, game->window,
		golem->death->sprite, golem->x, golem->y);
}

static void	print_taking_hit_golem(t_game *game, t_golem *golem)
{
	if (game->animation_state % 6 == 0)
	{
		golem->hit = golem->hit->next_frame;
		golem->hit_state--;
	}
	mlx_put_image_to_window(game->mlx, game->window,
		golem->hit->sprite, golem->x, golem->y);
	if (!golem->hit_state)
	{
		golem->hit_state = 4;
		golem->hit = golem->hit->next_frame;
		golem->status = ALIVE;
	}
}

void	print_golem(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->nb_golem)
	{
		if (game->golem[i]->status == ALIVE)
			print_alive_golem(game, game->golem[i]);
		else if (game->golem[i]->status == DEAD)
			print_dead_golem(game, game->golem[i]);
		else if (game->golem[i]->status == ATTACK)
			print_attacking_golem(game, game->golem[i]);
		else if (game->golem[i]->status == TAKING_DAMAGE)
			print_taking_hit_golem(game, game->golem[i]);
		i++;
	}
}
