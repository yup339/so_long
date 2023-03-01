/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   golem_texture2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 05:19:36 by pbergero          #+#    #+#             */
/*   Updated: 2023/01/25 05:46:39 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/sprites.h"

static	void	get_golem_idle_sprite2(t_game *game, int x, int y)
{
	game->golem[0]->idle->next_frame = malloc(sizeof(t_sprite));
	game->golem[0]->idle = game->golem[0]->idle->next_frame;
	game->golem[0]->idle->sprite
		= mlx_xpm_file_to_image(game->mlx, GOLEM5, &x, &y);
	game->golem[0]->idle->next_frame = malloc(sizeof(t_sprite));
	game->golem[0]->idle = game->golem[0]->idle->next_frame;
	game->golem[0]->idle->sprite
		= mlx_xpm_file_to_image(game->mlx, GOLEM6, &x, &y);
	game->golem[0]->idle->next_frame = malloc(sizeof(t_sprite));
	game->golem[0]->idle = game->golem[0]->idle->next_frame;
	game->golem[0]->idle->sprite
		= mlx_xpm_file_to_image(game->mlx, GOLEM7, &x, &y);
	game->golem[0]->idle->next_frame = malloc(sizeof(t_sprite));
	game->golem[0]->idle = game->golem[0]->idle->next_frame;
	game->golem[0]->idle->sprite
		= mlx_xpm_file_to_image(game->mlx, GOLEM4, &x, &y);
}

void	get_golem_idle_sprite(t_game *game)
{
	int			x;
	int			y;
	t_sprite	*temp;

	game->golem[0]->idle = malloc(sizeof(t_sprite));
	temp = game->golem[0]->idle;
	game->golem[0]->idle->sprite
		= mlx_xpm_file_to_image(game->mlx, GOLEM1, &x, &y);
	game->golem[0]->idle->next_frame = malloc(sizeof(t_sprite));
	game->golem[0]->idle = game->golem[0]->idle->next_frame;
	game->golem[0]->idle->sprite
		= mlx_xpm_file_to_image(game->mlx, GOLEM2, &x, &y);
	game->golem[0]->idle->next_frame = malloc(sizeof(t_sprite));
	game->golem[0]->idle = game->golem[0]->idle->next_frame;
	game->golem[0]->idle->sprite
		= mlx_xpm_file_to_image(game->mlx, GOLEM3, &x, &y);
	game->golem[0]->idle->next_frame = malloc(sizeof(t_sprite));
	game->golem[0]->idle = game->golem[0]->idle->next_frame;
	game->golem[0]->idle->sprite
		= mlx_xpm_file_to_image(game->mlx, GOLEM4, &x, &y);
	get_golem_idle_sprite2(game, x, y);
	game->golem[0]->idle->next_frame = temp;
}
