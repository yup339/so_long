/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 01:27:34 by pbergero          #+#    #+#             */
/*   Updated: 2023/02/25 15:08:18 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../include/flood_fill.h"
#include "../libft/include/libft.h"

int	close_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	free_game(game);
	exit (0);
	return (0);
}

static	int	key_event(int key, t_game *game)
{
	if (key == 40)
		kill_all_entity(game);
	if (game->player->status == DEAD)
		return (0);
	if (key == 13)
		move_up(game);
	if (key == 2)
		move_right(game);
	if (key == 1)
		move_down(game);
	if (key == 0)
		move_left(game);
	if (key == 49)
		game->player->status = ATTACK;
	return (0);
}

int	main_loop(t_game *game)
{
	game->animation_state++;
	if (game->animation_state == 4000)
		game->animation_state = 0;
	mlx_clear_window(game->mlx, game->window);
	if (game->nb_enemie)
		move_mage(game);
	if (game->nb_necro)
		move_necro(game);
	if (game->nb_golem)
		move_golem(game);
	check_collision(game);
	check_entity_collision(game);
	if (game->player->status == ATTACK)
		attack_action(game);
	print_map(game);
	if (game->nb_enemie)
		print_enemie(game);
	if (game->nb_golem)
		print_golem(game);
	print_player(game);
	if (game->nb_necro)
		print_necro(game);
	if (game->nb_boss)
		print_boss(game);
	return (1);
}

int	stop_move(int key, t_game *game)
{
	if ((key == 13 || key == 1 || key == 2 || key == 0 || key == 49)
		&& game->player->status != DEAD)
		game->player->status = ALIVE;
	if (key == 8)
	{
		game->move_count += 50;
		game->player->status = ALIVE;
	}
	if (key == 48 && game->player->direction == RIGHT
		&& game->player->status != DEAD)
		game->player->direction = LEFT;
	else if (key == 48 && game->player->direction == LEFT
		&& game->player->status != DEAD)
		game->player->direction = RIGHT;
	if (key == 53)
		close_game(game);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (!read_map(&game, argv, argc))
		exit (0);
	game.mlx = mlx_init();
	game.animation_state = 0;
	game.move_count = 0;
	create_entity(&game);
	get_images(&game);
	if (!flood_fill(ft_split(game.str, '\n'), game.nb_collectable))
	{
		free_game(&game);
		exit (0);
	}
	game.window = mlx_new_window(game.mlx, game.width * SPRITE_RES,
			(game.height * SPRITE_RES + SPRITE_RES), "so_long");
	mlx_hook(game.window, 02, 0L, key_event, &game);
	mlx_hook(game.window, 17, 0, close_game, &game);
	mlx_key_hook(game.window, stop_move, &game);
	mlx_loop_hook(game.mlx, main_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}
