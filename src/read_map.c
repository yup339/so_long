/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 03:44:52 by pbergero          #+#    #+#             */
/*   Updated: 2023/02/25 16:28:35 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../libft/include/libft.h"
#include <fcntl.h>

static int	add_map(char *map_path, t_game *game)
{
	int		fd;
	char	*str;

	fd = open(map_path, O_RDONLY);
	str = get_next_line(fd);
	if (!str)
	{
		printf("ERROR : reading file error\n");
		exit (0);
	}
	game->str = str;
	while (str)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		if (str[0] == '\n')
		{
			free(str);
			return (close(fd), print_error("empty line in map file", NULL));
		}
		game->str = ft_strjoin(game->str, str, 1, 1);
	}
	close(fd);
	return (1);
}

static int	check_extension(char *path)
{
	int	len;

	len = ft_strlen(path);
	path += len - 4;
	if (ft_strncmp(".ber", path, 4))
	{
		printf("ERROR : This is not a .ber file\n");
		return (0);
	}
	return (1);
}

int	check_char(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (!ft_strchr("10CEPBbMNDG\n", game->map[y][x]))
			{
				printf("ERROR : invalid char\n");
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

static int	check_border(t_game *game)
{
	int	x;

	x = -1;
	if (!check_border_side(game))
		return (0);
	while (game->map[0][++x])
	{
		if (game->map[0][x] != '1')
			return (print_error("map is not closed", game->map));
	}
	x = -1;
	while (game->map[game->height - 1][++x])
	{
		if (game->map[game->height - 1][x] != '1')
			return (print_error("error reading file map", game->map));
	}
	return (1);
}

int	read_map(t_game *game, char **argv, int argc)
{
	char	*map_path;

	if (argc != 2)
		return (print_error("Wrong number of argument", NULL));
	map_path = argv[1];
	if (!check_extension(map_path))
		return (0);
	if (!add_map(map_path, game))
	{
		if (game->str)
			free(game->str);
		return (0);
	}
	game->map = ft_split(game->str, '\n');
	if (!check_map_is_square(game))
		exit (0);
	if (!check_char(game) || !check_border(game)
		|| !check_essential_char(game) || !check_entity_space(game))
	{
		free (game->str);
		exit (0);
	}
	return (1);
}
