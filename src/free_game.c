/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:43:27 by pbergero          #+#    #+#             */
/*   Updated: 2023/02/19 20:08:06 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../libft/include/libft.h"

void	free_texture(void *mlx, t_sprite *sprite, int i)
{
	t_sprite	*temp;

	while (i)
	{
		mlx_destroy_image(mlx, sprite->sprite);
		temp = sprite->next_frame;
		sprite->next_frame = NULL;
		free(sprite);
		sprite = temp;
		i--;
	}
}

static void	free_player(t_game *game)
{
	free_texture(game->mlx, game->player->r_attack, 3);
	free_texture(game->mlx, game->player->attack, 3);
	free_texture(game->mlx, game->player->dead, 3);
	free_texture(game->mlx, game->player->r_dead, 3);
	free_texture(game->mlx, game->player->run, 4);
	free_texture(game->mlx, game->player->r_run, 4);
	free_texture(game->mlx, game->player->idle, 4);
	free_texture(game->mlx, game->player->r_idle, 4);
	free(game->player);
}

static void	free_enemie(t_game *game)
{
	int	i;

	i = 0;
	free_texture(game->mlx, game->enemie[0]->run, 4);
	free_texture(game->mlx, game->enemie[0]->r_run, 4);
	free_texture(game->mlx, game->enemie[0]->dead, 3);
	free_texture(game->mlx, game->enemie[0]->r_dead, 3);
	while (game->enemie[i])
	{
		free (game->enemie[i]);
		i++;
	}
	free(game->enemie);
}

static void	free_barrel(t_game *game)
{
	int	i;

	i = 0;
	free_texture(game->mlx, game->barel[0]->explosion, 4);
	free_texture(game->mlx, game->barel[0]->sprite, 2);
	while (i < game->nb_barrel)
	{
		free (game->barel[i]);
		i++;
	}
	free(game->barel);
}

void	free_game(t_game *game)
{
	if (game->player)
		free_player(game);
	if (game->enemie)
		free_enemie(game);
	if (game->barel)
		free_barrel(game);
	if (game->coll)
		free_texture(game->mlx, game->coll, 5);
	if (game->exit)
		free_texture(game->mlx, game->exit, 4);
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->grass)
		mlx_destroy_image(game->mlx, game->grass);
	if (game->str)
		free(game->str);
	if (game->map)
		free_double_array((void **)game->map);
	if (game->necro)
		free_necro(game);
	if (game->boss)
		free_boss(game);
	if (game->golem)
		free_golem(game);
}
