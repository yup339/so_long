/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   golem_fight.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 06:38:24 by pbergero          #+#    #+#             */
/*   Updated: 2023/02/21 17:58:09 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	golem_is_attack(t_entitie *player, t_golem *golem)
{
	if (player->direction == RIGHT)
	{
		if (player->x < golem->x + 155
			&& player->x + 75 + ATTACK_RANGE > golem->x
			&& player->y < golem->y + 150 && player->y + 75 > golem->y)
			return (1);
	}
	else
	{
		if (player->x - ATTACK_RANGE < golem->x + 155
			&& player->x > golem->x + 5
			&& player->y < golem->y + 150 && player->y + 75 > golem->y)
			return (1);
	}
	return (0);
}

int	golem_see_you(t_game *game, t_golem *golem)
{
	if (golem->status == DEAD)
		return (0);
	if (game->player->x < golem->x + 155 + GOLEM_VISION
		&& game->player->x + 75 > golem->x - SPRITE_RES - GOLEM_VISION
		&& game->player->y < golem->y + 150
		&& game->player->y + 75 > golem->y
		&& game->animation_state % GOLEM_ATTACK_SPEED == 0)
		return (1);
	return (0);
}

static int	golem_attack(t_entitie *player, t_golem *golem)
{
	if (golem->status == DEAD)
		return (0);
	if (golem->status == ATTACK
		&& golem->attacking_state == 4)
	{
		if (player->x < golem->x + 150 + 75 && player->x + 50 > golem->x - 75
			&& player->y < golem->y + 150 && player->y + 75 > golem->y)
			return (1);
	}
	else
	{
		if (player->x < golem->x + 150 && player->x + 50 > golem->x
			&& player->y < golem->y + 150 && player->y + 75 > golem->y)
			return (1);
	}
	return (0);
}

void	golem_attack_player(t_game *game)
{
	int	i;

	i = 0;
	if (!game->nb_golem)
		return ;
	while (game->golem[i])
	{
		if (golem_see_you(game, game->golem[i]))
			game->golem[i]->status = ATTACK;
		if (golem_attack(game->player, game->golem[i]))
			game->player->status = DEAD;
		i++;
	}
}

void	attack_golem(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->nb_golem)
	{
		if (golem_is_attack(game->player, game->golem[i])
			&& game->golem[i]->status != DEAD)
		{
			game->golem[i]->hp -= ATTACK_DAMAGE;
			if (game->golem[i]->status != ATTACK)
				game->golem[i]->status = TAKING_DAMAGE;
		}
		if (game->golem[i]->hp <= 0)
			game->golem[i]->status = DEAD;
		i++;
	}
}
