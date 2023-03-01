/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   barel_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:00:33 by pbergero          #+#    #+#             */
/*   Updated: 2023/01/17 11:04:42 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/sprites.h"

static void	add_texture_to_other_barrel(t_game *game)
{
	int	i;

	i = 1;
	while (i < game->nb_barrel)
	{
		game->barel[i]->sprite = game->barel[0]->sprite;
		game->barel[i]->explosion = game->barel[0]->explosion;
		i++;
	}
}

static void	get_explosion_texture(t_game *game)
{
	int			x;
	int			y;
	t_sprite	*temp;

	game->barel[0]->explosion = malloc(sizeof(t_sprite));
	temp = game->barel[0]->explosion;
	game->barel[0]->explosion->sprite
		= mlx_xpm_file_to_image(game->mlx, EXPLOSION2, &x, &y);
	game->barel[0]->explosion->next_frame = malloc(sizeof(t_sprite));
	game->barel[0]->explosion = game->barel[0]->explosion->next_frame;
	game->barel[0]->explosion->sprite
		= mlx_xpm_file_to_image(game->mlx, EXPLOSION3, &x, &y);
	game->barel[0]->explosion->next_frame = malloc(sizeof(t_sprite));
	game->barel[0]->explosion = game->barel[0]->explosion->next_frame;
	game->barel[0]->explosion->sprite
		= mlx_xpm_file_to_image(game->mlx, EXPLOSION4, &x, &y);
	game->barel[0]->explosion->next_frame = malloc(sizeof(t_sprite));
	game->barel[0]->explosion = game->barel[0]->explosion->next_frame;
	game->barel[0]->explosion->sprite
		= mlx_xpm_file_to_image(game->mlx, EXPLOSION1, &x, &y);
	game->barel[0]->explosion->next_frame = temp;
}

void	get_barrel_sprite(t_game *game)
{
	int			x;
	int			y;
	t_sprite	*temp;

	game->barel[0]->sprite = malloc(sizeof(t_sprite));
	temp = game->barel[0]->sprite;
	game->barel[0]->sprite->sprite
		= mlx_xpm_file_to_image(game->mlx, BARREL2, &x, &y);
	game->barel[0]->sprite->next_frame = malloc(sizeof(t_sprite));
	game->barel[0]->sprite = game->barel[0]->sprite->next_frame;
	game->barel[0]->sprite->sprite
		= mlx_xpm_file_to_image(game->mlx, BARREL1, &x, &y);
	game->barel[0]->sprite->next_frame = temp;
	get_explosion_texture(game);
	add_texture_to_other_barrel(game);
}

static void	move_barrel(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->nb_barrel)
	{
		if (game->barel[i]->content == EMPTY)
		{
			if (game->animation_state % 4 == 0
				&& game->barel[i]->state == ALIVE)
			{
				game->barel[i]->x += 1;
				game->barel[i]->y += 1;
			}
			else if (game->animation_state % 2 == 0
				&& game->barel[i]->state == ALIVE)
			{
				game->barel[i]->x -= 1;
				game->barel[i]->y -= 1;
			}
		}
		i++;
	}
}

void	print_barrel(t_game *game)
{
	int	i;

	i = 0;
	move_barrel(game);
	while (i < game->nb_barrel)
	{
		mlx_put_image_to_window(game->mlx, game->window,
			game->barel[i]->sprite->sprite,
			game->barel[i]->x, game->barel[i]->y);
		if (game->barel[i]->state == DEAD && game->barel[i]->dying_state
			&& game->barel[i]->content == EMPTY)
		{
			mlx_put_image_to_window(game->mlx, game->window,
				game->barel[i]->explosion->sprite,
				game->barel[i]->x, game->barel[i]->y);
			if (game->animation_state % 10 == 0)
			{
				game->barel[i]->explosion
					= game->barel[i]->explosion->next_frame;
				game->barel[i]->dying_state--;
			}	
		}
		i++;
	}
}
