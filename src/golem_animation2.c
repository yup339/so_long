/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   golem_animation2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 05:52:50 by pbergero          #+#    #+#             */
/*   Updated: 2023/01/29 12:35:11 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	print_attacking_golem(t_game *game, t_golem *golem)
{
	int	x;

	x = 0;
	if (game->animation_state % 10 == 0 && golem->attacking_state++ < 4)
	{
		golem->attack = golem->attack->next_frame;
		golem->r_attack = golem->r_attack->next_frame;
	}
	if (game->player->x > golem->x)
		mlx_put_image_to_window(game->mlx, game->window,
			golem->attack->sprite, golem->x + x, golem->y);
	else
	{
		if (golem->attacking_state == 4)
			x = -75;
		mlx_put_image_to_window(game->mlx, game->window,
			golem->r_attack->sprite, golem->x + x, golem->y);
	}
	if (golem->attacking_state == 4
		&& game->animation_state % 5 == 0 && game->animation_state % 10)
	{
		golem->status = ALIVE;
		golem->attacking_state = 0;
	}
}

static int	check_golem_up_collision(t_game *game, t_golem *golem)
{
	int	i;

	i = 0;
	while (i < game->nb_barrel)
	{
		if (golem->x < game->barel[i]->x + 50
			&& golem->x + 150 > game->barel[i]->x
			&& golem->y < game->barel[i]->y + 60
			&& golem->y + 150 > game->barel[i]->y + 15
			&& game->barel[i]->state == ALIVE)
			return (1);
		i++;
	}
	if (game->map[(golem->y / 75)][(golem->x / 75)] == '1'
		|| game->map[(golem->y / 75)][(golem->x / 75) + 1] == '1')
		return (1);
	return (0);
}

static int	check_golem_down_collision(t_game *game, t_golem *golem)
{
	int	i;

	i = 0;
	while (i < game->nb_barrel)
	{
		if (golem->x < game->barel[i]->x + 50
			&& golem->x + 150 > game->barel[i]->x
			&& golem->y < game->barel[i]->y + 60
			&& golem->y + 150 > game->barel[i]->y + 15
			&& game->barel[i]->state == ALIVE)
			return (1);
		i++;
	}
	if (game->map[((golem->y) / 75) + 2][(golem->x / 75)] == '1'
		|| game->map[((golem->y) / 75) + 2][(golem->x / 75) + 1] == '1')
		return (1);
	return (0);
}

static void	update_golem(t_game *game, t_golem *golem)
{
	if ((game->player->x < golem->x + 150 + GOLEM_VISION
			&& game->player->x + 75 > golem->x - GOLEM_VISION
			&& game->player->y < golem->y + 100
			&& game->player->y + 75 > golem->y + 50) || golem->status == DEAD)
		return ;
	if (golem->direction == UP)
	{
		if (check_golem_up_collision(game, golem))
		{
			golem->direction = DOWN;
			golem->y += GOLEM_SPEED;
		}
		else
			golem->y -= GOLEM_SPEED;
	}
	else
	{
		if (check_golem_down_collision(game, golem))
		{
			golem->direction = UP;
			golem->y -= GOLEM_SPEED;
		}
		else
			golem->y += GOLEM_SPEED;
	}
}

void	move_golem(t_game *game)
{
	int	i;

	i = 0;
	while (game->golem[i])
	{
		update_golem(game, game->golem[i]);
		i++;
	}
}
