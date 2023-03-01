/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mage_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:28:06 by pbergero          #+#    #+#             */
/*   Updated: 2023/01/17 17:16:29 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/sprites.h"

static void	get_enemie_run_texture(t_game *game)
{
	int			x;
	int			y;
	t_sprite	*temp;

	game->enemie[0]->run = malloc(sizeof(t_sprite));
	temp = game->enemie[0]->run;
	game->enemie[0]->run->sprite
		= mlx_xpm_file_to_image(game->mlx, MAGE1, &x, &y);
	game->enemie[0]->run->next_frame = malloc(sizeof(t_sprite));
	game->enemie[0]->run = game->enemie[0]->run->next_frame;
	game->enemie[0]->run->sprite
		= mlx_xpm_file_to_image(game->mlx, MAGE2, &x, &y);
	game->enemie[0]->run->next_frame = malloc(sizeof(t_sprite));
	game->enemie[0]->run = game->enemie[0]->run->next_frame;
	game->enemie[0]->run->sprite
		= mlx_xpm_file_to_image(game->mlx, MAGE3, &x, &y);
	game->enemie[0]->run->next_frame = malloc(sizeof(t_sprite));
	game->enemie[0]->run = game->enemie[0]->run->next_frame;
	game->enemie[0]->run->sprite
		= mlx_xpm_file_to_image(game->mlx, MAGE4, &x, &y);
	game->enemie[0]->run->next_frame = temp;
}

static void	get_enemie_reverse_run_texture(t_game *game)
{
	int			x;
	int			y;
	t_sprite	*temp;

	game->enemie[0]->r_run = malloc(sizeof(t_sprite));
	temp = game->enemie[0]->r_run;
	game->enemie[0]->r_run->sprite
		= mlx_xpm_file_to_image(game->mlx, R_MAGE1, &x, &y);
	game->enemie[0]->r_run->next_frame = malloc(sizeof(t_sprite));
	game->enemie[0]->r_run = game->enemie[0]->r_run->next_frame;
	game->enemie[0]->r_run->sprite
		= mlx_xpm_file_to_image(game->mlx, R_MAGE2, &x, &y);
	game->enemie[0]->r_run->next_frame = malloc(sizeof(t_sprite));
	game->enemie[0]->r_run = game->enemie[0]->r_run->next_frame;
	game->enemie[0]->r_run->sprite
		= mlx_xpm_file_to_image(game->mlx, R_MAGE3, &x, &y);
	game->enemie[0]->r_run->next_frame = malloc(sizeof(t_sprite));
	game->enemie[0]->r_run = game->enemie[0]->r_run->next_frame;
	game->enemie[0]->r_run->sprite
		= mlx_xpm_file_to_image(game->mlx, R_MAGE4, &x, &y);
	game->enemie[0]->r_run->next_frame = temp;
}

static void	get_enemie_dying_texture(t_game *game)
{
	int			x;
	int			y;
	t_sprite	*temp;

	game->enemie[0]->dead = malloc(sizeof(t_sprite));
	temp = game->enemie[0]->dead;
	game->enemie[0]->dead->sprite
		= mlx_xpm_file_to_image(game->mlx, DEAD_MAGE2, &x, &y);
	game->enemie[0]->dead->next_frame = malloc(sizeof(t_sprite));
	game->enemie[0]->dead = game->enemie[0]->dead->next_frame;
	game->enemie[0]->dead->sprite
		= mlx_xpm_file_to_image(game->mlx, DEAD_MAGE3, &x, &y);
	game->enemie[0]->dead->next_frame = malloc(sizeof(t_sprite));
	game->enemie[0]->dead = game->enemie[0]->dead->next_frame;
	game->enemie[0]->dead->sprite
		= mlx_xpm_file_to_image(game->mlx, DEAD_MAGE1, &x, &y);
	game->enemie[0]->dead->next_frame = temp;
}

static void	get_enemie_reverse_dying_texture(t_game *game)
{
	int			x;
	int			y;
	t_sprite	*temp;

	game->enemie[0]->r_dead = malloc(sizeof(t_sprite));
	temp = game->enemie[0]->r_dead;
	game->enemie[0]->r_dead->sprite
		= mlx_xpm_file_to_image(game->mlx, R_DEAD_MAGE2, &x, &y);
	game->enemie[0]->r_dead->next_frame = malloc(sizeof(t_sprite));
	game->enemie[0]->r_dead = game->enemie[0]->r_dead->next_frame;
	game->enemie[0]->r_dead->sprite
		= mlx_xpm_file_to_image(game->mlx, R_DEAD_MAGE3, &x, &y);
	game->enemie[0]->r_dead->next_frame = malloc(sizeof(t_sprite));
	game->enemie[0]->r_dead = game->enemie[0]->r_dead->next_frame;
	game->enemie[0]->r_dead->sprite
		= mlx_xpm_file_to_image(game->mlx, R_DEAD_MAGE1, &x, &y);
	game->enemie[0]->r_dead->next_frame = temp;
}

void	get_enemie_texture(t_game *game)
{
	int	i;

	i = 1;
	get_enemie_run_texture(game);
	get_enemie_reverse_run_texture(game);
	get_enemie_dying_texture(game);
	get_enemie_reverse_dying_texture(game);
	while (i < game->nb_enemie)
	{
		game->enemie[i]->run = game->enemie[0]->run;
		game->enemie[i]->r_run = game->enemie[0]->r_run;
		game->enemie[i]->dead = game->enemie[0]->dead;
		game->enemie[i]->r_dead = game->enemie[0]->r_dead;
		i++;
	}
}
