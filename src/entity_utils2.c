/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 04:54:19 by pbergero          #+#    #+#             */
/*   Updated: 2023/02/26 15:43:30 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../libft/include/libft.h"

int	create_golem(t_game *game, int y, int x, int f)
{
	game->golem[f] = ft_calloc(1, sizeof(t_golem) + 1);
	if (!game->golem[f])
		return (0);
	game->golem[f]->x = x * SPRITE_RES;
	game->golem[f]->y = y * SPRITE_RES;
	game->golem[f]->status = TAKING_DAMAGE;
	game->golem[f]->direction = UP;
	game->golem[f]->dying_state = 4;
	game->golem[f]->attacking_state = 1;
	game->golem[f]->hp = GOLEM_HP;
	game->golem[f]->hit_state = 5;
	return (1);
}

void	kill_all_entity(t_game *game)
{
	int	i;

	i = -1;
	while (game->nb_enemie > ++i)
		game->enemie[i]->status = DEAD;
	i = -1;
	while (game->nb_golem > ++i)
		game->golem[i]->status = DEAD;
	i = -1;
	while (game->nb_boss > ++i)
		game->boss[i]->status = DEAD;
	i = -1;
	while (game->nb_necro > ++i)
		game->necro[i]->status = DEAD;
	i = -1;
	while (game->nb_barrel > ++i)
	{
		if (game->barel[i]->content == ITEM && game->barel[i]->state == ALIVE)
			destroy_barrel(game, game->barel[i]);
		else if (game->barel[i]->state == ALIVE)
		{
			game->barel[i]->state = DEAD;
			game->barel[i]->sprite = game->barel[i]->sprite->next_frame;
		}
	}
}
