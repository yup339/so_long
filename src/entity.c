/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:46:36 by pbergero          #+#    #+#             */
/*   Updated: 2023/02/25 14:15:17 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../include/entity.h"
#include "../libft/include/libft.h"

int	get_nb_entity(char	*str, char entity_type)
{
	int	i;
	int	n;

	n = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == entity_type)
			n++;
		i++;
	}
	return (n);
}

static	void	builder_choice(t_game *game, t_entity_counter *count)
{
	if (game->map[count->y][count->x] == 'M')
		create_foe(game, count->y, count->x, count->mage++);
	else if (game->map[count->y][count->x] == 'P')
		create_player(game, count->y, count->x);
	else if (game->map[count->y][count->x] == 'B'
	|| game->map[count->y][count->x] == 'b')
		create_barrel(game, count->y, count->x, count->barrel++);
	else if (game->map[count->y][count->x] == 'N')
		create_necro(game, count->y, count->x, count->ghost++);
	else if (game->map[count->y][count->x] == 'D')
		create_boss(game, count->y, count->x, count->demon++);
	else if (game->map[count->y][count->x] == 'G')
		create_golem(game, count->y, count->x, count->golem++);
}

static int	build_entities(t_game *game)
{
	t_entity_counter	count;

	count.y = 0;
	count.barrel = 0;
	count.demon = 0;
	count.ghost = 0;
	count.golem = 0;
	count.mage = 0;
	while (count.y++ < game->height - 1)
	{
		count.x = 0;
		{
			while (count.x++ < game->width - 1)
			{
				builder_choice(game, &count);
			}
		}
	}
	return (1);
}

int	create_entity(t_game *game)
{
	game->nb_enemie = get_nb_entity(game->str, 'M');
	game->nb_barrel = get_nb_entity(game->str, 'B');
	game->nb_barrel += get_nb_entity(game->str, 'b');
	game->nb_collectable = get_nb_entity(game->str, 'C');
	game->nb_necro = get_nb_entity(game->str, 'N');
	game->nb_boss = get_nb_entity(game->str, 'D');
	game->nb_golem = get_nb_entity(game->str, 'G');
	if (game->nb_barrel != 0)
		game->barel = ft_calloc(game->nb_barrel + 1, sizeof(t_barrel *));
	if (game->nb_enemie != 0)
		game->enemie = ft_calloc(game->nb_enemie + 1, sizeof(t_entitie *));
	if (game->nb_necro != 0)
		game->necro = ft_calloc(game->nb_necro + 1, sizeof(t_entitie *));
	if (game->nb_boss != 0)
		game->boss = ft_calloc(game->nb_boss + 1, sizeof(t_boss *));
	if (game->nb_golem != 0)
		game->golem = ft_calloc(game->nb_golem + 1, sizeof(t_golem *));
	build_entities(game);
	return (1);
}
