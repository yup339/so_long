/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boss_fight.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:28:17 by pbergero          #+#    #+#             */
/*   Updated: 2023/01/25 08:37:31 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	boss_is_attack(t_entitie *player, t_boss *boss)
{
	if (player->direction == RIGHT)
	{
		if (player->x < boss->x + 155 && player->x + 75 + ATTACK_RANGE > boss->x
			&& player->y < boss->y + 150 && player->y + 75 > boss->y)
			return (1);
	}
	else
	{
		if (player->x - ATTACK_RANGE < boss->x + 155 && player->x > boss->x + 5
			&& player->y < boss->y + 150 && player->y + 75 > boss->y)
			return (1);
	}
	return (0);
}

int	boss_see_you(t_game *game, t_boss *boss)
{
	if (boss->status == DEAD)
		return (0);
	if (game->player->x < boss->x + 155 + BOSS_RANGE
		&& game->player->x + 75 > boss->x - SPRITE_RES - BOSS_RANGE
		&& game->player->y < boss->y + 150 + BOSS_RANGE_HEIGHT
		&& game->player->y + 75 > boss->y - BOSS_RANGE_HEIGHT
		&& game->animation_state % 100 == 0)
		return (1);
	return (0);
}

void	attack_boss(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->nb_boss)
	{
		if (boss_is_attack(game->player, game->boss[i])
			&& game->boss[i]->status != DEAD)
		{
			game->boss[i]->hp -= ATTACK_DAMAGE;
			if (game->boss[i]->status != ATTACK)
				game->boss[i]->status = TAKING_DAMAGE;
		}
		if (game->boss[i]->hp <= 0)
			game->boss[i]->status = DEAD;
		i++;
	}
}
