/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:38:38 by pbergero          #+#    #+#             */
/*   Updated: 2023/02/21 21:36:33 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	mage_attack_player(t_entitie *player, t_entitie *mage)
{
	if (mage->status == DEAD)
		return (0);
	if (player->x < mage->x + 50 && player->x + 50 > mage->x
		&& player->y < mage->y + 75 && player->y + 75 > mage->y)
		return (1);
	return (0);
}

static int	ghost_attack_player(t_entitie *player, t_entitie *ghost)
{
	if (player->x < ghost->x + 50 && player->x + 50 > ghost->x
		&& player->y < ghost->y + 75 && player->y + 75 > ghost->y
		&& ghost->status == ALIVE)
		return (1);
	return (0);
}

static int	boss_attack(t_entitie *player, t_boss *boss)
{
	if (boss->status == DEAD)
		return (0);
	if (boss->status == ATTACK
		&& (boss->attacking_state == 6
			|| boss->attacking_state == 7))
	{
		if (player->x < boss->x + 150 && player->x + 50 > boss->x - 75
			&& player->y < boss->y + 150 && player->y + 75 > boss->y)
			return (1);
	}
	else
	{
		if (player->x < boss->x + 150 && player->x + 50 > boss->x
			&& player->y < boss->y + 150 && player->y + 75 > boss->y)
			return (1);
	}
	return (0);
}

void	check_entity_collision(t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->nb_enemie)
		if (mage_attack_player(game->player, game->enemie[i]))
			game->player->status = DEAD;
	i = -1;
	while (++i < game->nb_necro)
		if (ghost_attack_player(game->player, game->necro[i]))
			game->player->status = DEAD;
	i = -1;
	while (++i < game->nb_boss)
	{
		if (boss_see_you(game, game->boss[i]))
			game->boss[i]->status = ATTACK;
		if (boss_attack(game->player, game->boss[i])
			&& game->player->status != DEAD)
		{
			game->player->status = DEAD;
			system("open https://www.youtube.com/watch?v=dQw4w9WgXcQ");
		}
	}
	golem_attack_player(game);
}

void	check_collision(t_game *game)
{
	if (game->map[(game->player->y + 32) / 75][((game->player->x + 32) / 75)] ==
		'C')
	{
		game->nb_collectable--;
		game->map[(game->player->y + 32) / 75]
		[((game->player->x + 32) / 75)] = '0';
	}
	if (game->map[(game->player->y + 32) / 75][((game->player->x + 32) / 75)] ==
		'E' && game->nb_collectable == 0)
		close_game(game);
}
