/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   necro_animation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:41:50 by pbergero          #+#    #+#             */
/*   Updated: 2023/01/19 22:09:34 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	print_necro(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->nb_necro)
	{
		if (game->necro[i]->direction == RIGHT)
		{
			if (game->animation_state % 4 == 0)
				game->necro[i]->idle = game->necro[i]->idle->next_frame;
			mlx_put_image_to_window(game->mlx, game->window,
				game->necro[i]->idle->sprite,
				game->necro[i]->x, game->necro[i]->y);
		}
		else
		{
			if (game->animation_state % 4 == 0)
				game->necro[i]->r_idle = game->necro[i]->r_idle->next_frame;
			mlx_put_image_to_window(game->mlx, game->window,
				game->necro[i]->r_idle->sprite,
				game->necro[i]->x, game->necro[i]->y);
		}
		i++;
	}
}

static void	update_necro(t_game *game, t_entitie *necro)
{
	if (game->player->x > necro->x)
	{
		necro->direction = RIGHT;
		necro->x += NECRO_SPEED;
	}
	else if (game->player->x < necro->x)
	{
		necro->direction = LEFT;
		necro->x -= NECRO_SPEED;
	}
	if (game->player->y > necro->y)
		necro->y += NECRO_SPEED;
	else if (game->player->y < necro->y)
		necro->y -= NECRO_SPEED;
}

void	move_necro(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->nb_necro)
	{
		update_necro(game, game->necro[i]);
		i++;
	}
}
