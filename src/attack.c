/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attack.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:54:49 by pbergero          #+#    #+#             */
/*   Updated: 2023/02/21 22:11:08 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	is_attack(t_game *game, int x, int y)
{
	if (game->player->direction == LEFT)
	{
		if (game->player->x - ATTACK_RANGE < x + 75 && game->player->x > x
			&& game->player->y + 5 < y + 75 && game->player->y + 65 > y)
		{
			return (1);
		}
	}
	else
	{
		if (game->player->x + 75 < x + 75
			&& game->player->x + 75 + ATTACK_RANGE > x
			&& game->player->y + 5 < y + 75 && game->player->y + 65 > y)
		{
			return (1);
		}
	}
	if (game->player->x + 20 < x + 75 && game->player->x + 35 > x
		&& game->player->y - ATTACK_HEIGHT < y + 75
		&& game->player->y + ATTACK_HEIGHT + 75 > y)
		return (1);
	return (0);
}

void	destroy_barrel(t_game *game, t_barrel *barrel)
{
	barrel->state = DEAD;
	barrel->sprite = barrel->sprite->next_frame;
	if (barrel->content == ITEM)
		game->map[barrel->y / 75][barrel->x / 75] = 'C';
	else
		game->player->status = DEAD;
}

static void	attack_barrel(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->nb_barrel)
	{
		if (is_attack(game, game->barel[i]->x, game->barel[i]->y)
			&& game->barel[i]->state == ALIVE)
			destroy_barrel(game, game->barel[i]);
		i++;
	}
}

static void	attack_enemie(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->nb_enemie)
	{
		if (is_attack(game, game->enemie[i]->x, game->enemie[i]->y)
			&& game->enemie[i]->status == ALIVE)
			game->enemie[i]->status = DEAD;
		i++;
	}
}

void	attack_action(t_game *game)
{
	if (game->nb_barrel)
		attack_barrel(game);
	if (game->nb_enemie)
		attack_enemie(game);
	if (game->nb_boss)
		attack_boss(game);
	if (game->nb_golem)
		attack_golem(game);
}
