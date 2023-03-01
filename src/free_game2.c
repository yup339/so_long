/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:41:26 by pbergero          #+#    #+#             */
/*   Updated: 2023/01/27 12:05:28 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../libft/include/libft.h"

void	free_necro(t_game *game)
{
	int	i;

	i = 0;
	free_texture(game->mlx, game->necro[0]->idle, 10);
	free_texture(game->mlx, game->necro[0]->r_idle, 10);
	while (game->necro[i])
	{
		free (game->necro[i]);
		i++;
	}
	free(game->necro);
}

void	free_boss(t_game *game)
{
	int	i;

	i = 0;
	free_texture(game->mlx, game->boss[0]->attack, 8);
	free_texture(game->mlx, game->boss[0]->idle, 6);
	free_texture(game->mlx, game->boss[0]->death, 11);
	free_texture(game->mlx, game->boss[0]->hit, 5);
	while (game->boss[i])
	{
		free (game->boss[i]);
		i++;
	}
	free(game->boss);
}

void	free_golem(t_game *game)
{
	int	i;

	i = 0;
	free_texture(game->mlx, game->golem[0]->attack, 4);
	free_texture(game->mlx, game->golem[0]->r_attack, 4);
	free_texture(game->mlx, game->golem[0]->idle, 8);
	free_texture(game->mlx, game->golem[0]->death, 5);
	free_texture(game->mlx, game->golem[0]->hit, 4);
	while (game->golem[i])
	{
		free (game->golem[i]);
		i++;
	}
	free(game->golem);
}
