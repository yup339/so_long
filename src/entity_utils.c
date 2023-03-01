/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:25:11 by pbergero          #+#    #+#             */
/*   Updated: 2023/01/24 20:31:21 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../libft/include/libft.h"

int	create_player(t_game *game, int y, int x)
{
	game->player = ft_calloc(1, sizeof(t_entitie));
	if (!game->player)
		return (0);
	game->player->type = PLAYER_TYPE;
	game->player->x = x * SPRITE_RES;
	game->player->y = y * SPRITE_RES;
	game->player->status = ALIVE;
	game->player->direction = RIGHT;
	game->player->dying_state = 2;
	return (1);
}

int	create_foe(t_game *game, int y, int x, int f)
{
	game->enemie[f] = ft_calloc(1, sizeof(t_entitie));
	if (!game->enemie[f])
		return (0);
	game->enemie[f]->type = MAGE_TYPE;
	game->enemie[f]->x = x * SPRITE_RES;
	game->enemie[f]->y = y * SPRITE_RES;
	game->enemie[f]->status = ALIVE;
	if (f % 2)
		game->enemie[f]->direction = RIGHT;
	else
		game->enemie[f]->direction = LEFT;
	game->enemie[f]->dying_state = 2;
	return (1);
}

int	create_barrel(t_game *game, int y, int x, int b)
{
	game->barel[b] = ft_calloc(1, sizeof(t_barrel));
	if (!game->barel[b])
		return (0);
	if (game->map[y][x] == 'B')
		game->barel[b]->content = EMPTY;
	else
	{
		game->barel[b]->content = ITEM;
		game->nb_collectable++;
	}
	game->barel[b]->state = ALIVE;
	game->barel[b]->x = x * SPRITE_RES;
	game->barel[b]->y = y * SPRITE_RES;
	game->barel[b]->dying_state = 4;
	return (1);
}

int	create_necro(t_game *game, int y, int x, int f)
{
	game->necro[f] = ft_calloc(1, sizeof(t_entitie));
	if (!game->necro[f])
		return (0);
	game->necro[f]->type = MAGE_TYPE;
	game->necro[f]->x = x * SPRITE_RES;
	game->necro[f]->y = y * SPRITE_RES;
	game->necro[f]->status = ALIVE;
	if (f % 2)
		game->necro[f]->direction = RIGHT;
	else
		game->necro[f]->direction = LEFT;
	game->necro[f]->dying_state = 2;
	return (1);
}

int	create_boss(t_game *game, int y, int x, int f)
{
	game->boss[f] = ft_calloc(1, sizeof(t_boss) + 1);
	if (!game->boss[f])
		return (0);
	game->boss[f]->x = x * SPRITE_RES;
	game->boss[f]->y = y * SPRITE_RES;
	game->boss[f]->status = ALIVE;
	game->boss[f]->dying_state = 9;
	game->boss[f]->attacking_state = 1;
	game->boss[f]->hp = BOSS_HP;
	game->boss[f]->hit_state = 5;
	return (1);
}
