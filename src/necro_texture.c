/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   necro_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:26:38 by pbergero          #+#    #+#             */
/*   Updated: 2023/02/02 18:55:10 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/sprites.h"

static void	get_necro_idle_texture2(t_game *game, int x, int y)
{
	game->necro[0]->idle->next_frame = malloc(sizeof(t_sprite));
	game->necro[0]->idle = game->necro[0]->idle->next_frame;
	game->necro[0]->idle->sprite
		= mlx_xpm_file_to_image(game->mlx, GHOST5, &x, &y);
	game->necro[0]->idle->next_frame = malloc(sizeof(t_sprite));
	game->necro[0]->idle = game->necro[0]->idle->next_frame;
	game->necro[0]->idle->sprite
		= mlx_xpm_file_to_image(game->mlx, GHOST6, &x, &y);
	game->necro[0]->idle->next_frame = malloc(sizeof(t_sprite));
	game->necro[0]->idle = game->necro[0]->idle->next_frame;
	game->necro[0]->idle->sprite
		= mlx_xpm_file_to_image(game->mlx, GHOST7, &x, &y);
	game->necro[0]->idle->next_frame = malloc(sizeof(t_sprite));
	game->necro[0]->idle = game->necro[0]->idle->next_frame;
	game->necro[0]->idle->sprite
		= mlx_xpm_file_to_image(game->mlx, GHOST8, &x, &y);
	game->necro[0]->idle->next_frame = malloc(sizeof(t_sprite));
	game->necro[0]->idle = game->necro[0]->idle->next_frame;
	game->necro[0]->idle->sprite
		= mlx_xpm_file_to_image(game->mlx, GHOST9, &x, &y);
	game->necro[0]->idle->next_frame = malloc(sizeof(t_sprite));
	game->necro[0]->idle = game->necro[0]->idle->next_frame;
	game->necro[0]->idle->sprite
		= mlx_xpm_file_to_image(game->mlx, GHOST0, &x, &y);
}

static void	get_necro_idle_texture(t_game *game)
{
	int			x;
	int			y;
	t_sprite	*temp;

	game->necro[0]->idle = malloc(sizeof(t_sprite));
	temp = game->necro[0]->idle;
	game->necro[0]->idle->sprite
		= mlx_xpm_file_to_image(game->mlx, GHOST1, &x, &y);
	game->necro[0]->idle->next_frame = malloc(sizeof(t_sprite));
	game->necro[0]->idle = game->necro[0]->idle->next_frame;
	game->necro[0]->idle->sprite
		= mlx_xpm_file_to_image(game->mlx, GHOST2, &x, &y);
	game->necro[0]->idle->next_frame = malloc(sizeof(t_sprite));
	game->necro[0]->idle = game->necro[0]->idle->next_frame;
	game->necro[0]->idle->sprite
		= mlx_xpm_file_to_image(game->mlx, GHOST3, &x, &y);
	game->necro[0]->idle->next_frame = malloc(sizeof(t_sprite));
	game->necro[0]->idle = game->necro[0]->idle->next_frame;
	game->necro[0]->idle->sprite
		= mlx_xpm_file_to_image(game->mlx, GHOST4, &x, &y);
	get_necro_idle_texture2(game, x, y);
	game->necro[0]->idle->next_frame = temp;
}

static void	get_necro_reverse_idle_texture2(t_game *game, int x, int y)
{
	game->necro[0]->r_idle->next_frame = malloc(sizeof(t_sprite));
	game->necro[0]->r_idle = game->necro[0]->r_idle->next_frame;
	game->necro[0]->r_idle->sprite
		= mlx_xpm_file_to_image(game->mlx, R_GHOST5, &x, &y);
	game->necro[0]->r_idle->next_frame = malloc(sizeof(t_sprite));
	game->necro[0]->r_idle = game->necro[0]->r_idle->next_frame;
	game->necro[0]->r_idle->sprite
		= mlx_xpm_file_to_image(game->mlx, R_GHOST6, &x, &y);
	game->necro[0]->r_idle->next_frame = malloc(sizeof(t_sprite));
	game->necro[0]->r_idle = game->necro[0]->r_idle->next_frame;
	game->necro[0]->r_idle->sprite
		= mlx_xpm_file_to_image(game->mlx, R_GHOST7, &x, &y);
	game->necro[0]->r_idle->next_frame = malloc(sizeof(t_sprite));
	game->necro[0]->r_idle = game->necro[0]->r_idle->next_frame;
	game->necro[0]->r_idle->sprite
		= mlx_xpm_file_to_image(game->mlx, R_GHOST8, &x, &y);
	game->necro[0]->r_idle->next_frame = malloc(sizeof(t_sprite));
	game->necro[0]->r_idle = game->necro[0]->r_idle->next_frame;
	game->necro[0]->r_idle->sprite
		= mlx_xpm_file_to_image(game->mlx, R_GHOST9, &x, &y);
	game->necro[0]->r_idle->next_frame = malloc(sizeof(t_sprite));
	game->necro[0]->r_idle = game->necro[0]->r_idle->next_frame;
	game->necro[0]->r_idle->sprite
		= mlx_xpm_file_to_image(game->mlx, R_GHOST0, &x, &y);
}

static void	get_necro_reverse_idle_texture(t_game *game)
{
	int			x;
	int			y;
	t_sprite	*temp;

	game->necro[0]->r_idle = malloc(sizeof(t_sprite));
	temp = game->necro[0]->r_idle;
	game->necro[0]->r_idle->sprite
		= mlx_xpm_file_to_image(game->mlx, R_GHOST1, &x, &y);
	game->necro[0]->r_idle->next_frame = malloc(sizeof(t_sprite));
	game->necro[0]->r_idle = game->necro[0]->r_idle->next_frame;
	game->necro[0]->r_idle->sprite
		= mlx_xpm_file_to_image(game->mlx, R_GHOST2, &x, &y);
	game->necro[0]->r_idle->next_frame = malloc(sizeof(t_sprite));
	game->necro[0]->r_idle = game->necro[0]->r_idle->next_frame;
	game->necro[0]->r_idle->sprite
		= mlx_xpm_file_to_image(game->mlx, R_GHOST3, &x, &y);
	game->necro[0]->r_idle->next_frame = malloc(sizeof(t_sprite));
	game->necro[0]->r_idle = game->necro[0]->r_idle->next_frame;
	game->necro[0]->r_idle->sprite
		= mlx_xpm_file_to_image(game->mlx, R_GHOST4, &x, &y);
	get_necro_reverse_idle_texture2(game, x, y);
	game->necro[0]->r_idle->next_frame = temp;
}

void	get_necro_texture(t_game *game)
{
	int	i;

	i = 1;
	get_necro_idle_texture(game);
	get_necro_reverse_idle_texture(game);
	while (i < game->nb_necro)
	{
		game->necro[i]->idle = game->necro[0]->idle;
		game->necro[i]->r_idle = game->necro[0]->r_idle;
		i++;
	}
}
