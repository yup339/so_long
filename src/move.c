/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 15:32:51 by pbergero          #+#    #+#             */
/*   Updated: 2023/01/29 17:52:48 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	barrel_collision(t_entitie *entity, t_barrel *barrel, int y, int x)
{
	if (barrel->state != ALIVE)
		return (0);
	if (entity->x + 10 + x < barrel->x + 75
		&& entity->x - 10 + x + 75 > barrel->x
		&& entity->y +10 + y < barrel->y + 75
		&& entity->y - 10 + y + 75 > barrel->y)
		return (1);
	return (0);
}

void	move_up(t_game *game)
{
	int	i;

	i = 0;
	game->player->status = MOVING;
	if (game->map[(game->player->y / 75) - 1][game->player->x / 75] == '1')
		return ;
	if (game->nb_barrel)
	{
		while (i < game->nb_barrel)
		{
			if (barrel_collision(game->player, game->barel[i], -75, 0))
				return ;
			i++;
		}
	}
	game->move_count++;
	game->player->y -= SPEED;
}

void	move_down(t_game *game)
{
	int	i;

	i = 0;
	game->player->status = MOVING;
	if (game->map[(game->player->y / 75) + 1][game->player->x / 75] == '1')
		return ;
	if (game->nb_barrel)
	{
		while (i < game->nb_barrel)
		{
			if (barrel_collision(game->player, game->barel[i], 75, 0))
				return ;
			i++;
		}
	}
	game->move_count++;
	game->player->y += SPEED;
}

void	move_left(t_game *game)
{
	int	i;

	i = 0;
	game->player->status = MOVING;
	game->player->direction = LEFT;
	if (game->map[game->player->y / 75][(game->player->x / 75) - 1] == '1')
		return ;
	if (game->nb_barrel)
	{
		while (i < game->nb_barrel)
		{
			if (barrel_collision(game->player, game->barel[i], 0, -75))
				return ;
			i++;
		}
	}
	game->move_count++;
	game->player->x -= SPEED;
}

void	move_right(t_game *game)
{
	int	i;

	i = 0;
	game->player->status = MOVING;
	game->player->direction = RIGHT;
	if (game->map[game->player->y / 75][(game->player->x / 75 + 1)] == '1')
		return ;
	if (game->nb_barrel)
	{
		while (i < game->nb_barrel)
		{
			if (barrel_collision(game->player, game->barel[i], 0, 75))
				return ;
			i++;
		}
	}
	game->move_count++;
	game->player->x += SPEED;
}
