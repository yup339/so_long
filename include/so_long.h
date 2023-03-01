/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 01:22:24 by pbergero          #+#    #+#             */
/*   Updated: 2023/02/25 16:27:22 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include<stdio.h>

typedef struct s_sprite{
	struct s_sprite	*next_frame;
	void			*sprite;
}	t_sprite;

typedef struct s_entitie{
	int			x;
	int			y;
	int			type;
	int			status;
	int			direction;
	int			dying_state;
	t_sprite	*run;
	t_sprite	*r_run;
	t_sprite	*attack;
	t_sprite	*r_attack;
	t_sprite	*dead;
	t_sprite	*r_dead;
	t_sprite	*idle;
	t_sprite	*r_idle;
}	t_entitie;

typedef struct s_barrel
{
	int			x;
	int			y;
	int			content;
	int			state;
	int			dying_state;
	t_sprite	*sprite;
	t_sprite	*explosion;
}	t_barrel;

typedef struct s_boss {
	int			x;
	int			y;
	int			status;
	int			dying_state;
	int			attacking_state;
	int			hit_state;
	int			hp;
	t_sprite	*hit;
	t_sprite	*attack;
	t_sprite	*death;
	t_sprite	*idle;
}	t_boss;

typedef struct s_golem {
	int			x;
	int			y;
	int			status;
	int			direction;
	int			dying_state;
	int			attacking_state;
	int			hit_state;
	int			hp;
	t_sprite	*hit;
	t_sprite	*attack;
	t_sprite	*r_attack;
	t_sprite	*death;
	t_sprite	*idle;
}	t_golem;

typedef struct s_game {
	void		*mlx;
	char		*window;
	char		**map;
	char		*str;
	int			nb_collectable;
	int			move_count;
	int			height;
	int			width;
	int			nb_enemie;
	int			nb_barrel;
	int			nb_necro;
	int			nb_boss;
	int			nb_golem;
	int			animation_state;
	t_sprite	*exit;
	t_sprite	*coll;
	void		*wall;
	void		*grass;
	t_entitie	*player;
	t_entitie	**enemie;
	t_entitie	**necro;
	t_boss		**boss;
	t_barrel	**barel;
	t_golem		**golem;
}	t_game;

# define DEFAULT_MAP "./maps/kill_the_boss.ber"

# define SPRITE_RES 75

# define PLAYER_TYPE 1
# define MAGE_TYPE 2

# define TAKING_DAMAGE 4
# define ATTACK 3
# define MOVING 2
# define ALIVE 1
# define DEAD 0

# define EMPTY 0
# define ITEM 1

# define LEFT 1
# define RIGHT 2
# define UP 4
# define DOWN 3

# define BOSS_RANGE 75
# define BOSS_RANGE_HEIGHT 75
# define ATTACK_RANGE 70 
# define ATTACK_HEIGHT 25
# define ATTACK_DAMAGE 10
# define BOSS_HP 1000
# define GOLEM_HP 500
# define SPEED 75
# define MAGE_SPEED 5
# define NECRO_SPEED 1
# define GOLEM_SPEED 3
# define GOLEM_VISION 3
# define GOLEM_ATTACK_SPEED 100 

int		read_map(t_game *game, char **argv, int argc);
int		check_border_side(t_game *game);
int		check_essential_char(t_game *game);
int		check_map_is_square(t_game *game);
int		check_entity_space(t_game *game);
char	*ft_strjoin(char *s1, char *s2, int flag1, int flag2);
void	print_cell(t_game *game, int x, int y);
void	get_images(t_game *game);
int		close_game(t_game *game);
int		get_nb_entity(char	*str, char entity_type);
void	get_tiles_sprites(t_game *game);
void	get_barrel_sprite(t_game *game);
void	get_enemie_texture(t_game *game);
void	get_necro_texture(t_game *game);
void	get_boss_texture(t_game *game);
void	get_golem_texture(t_game *game);
void	attack_boss(t_game *game);
void	put_str_to_screen(t_game *game);
int		print_error(char *msg, char **map);

void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_right(t_game *game);
void	move_left(t_game *game);
void	kill_all_entity(t_game *game);
int		barrel_collision(t_entitie *entity, t_barrel *barrel, int y, int x);
void	destroy_barrel(t_game *game, t_barrel *barrel);

void	print_player(t_game *game);
int		create_necro(t_game *game, int y, int x, int f);
int		create_entity(t_game *game);
int		create_barrel(t_game *game, int y, int x, int b);
int		create_foe(t_game *game, int y, int x, int f);
int		create_boss(t_game *game, int y, int x, int f);
int		create_player(t_game *game, int y, int x);
int		create_golem(t_game *game, int y, int x, int f);
void	check_collision(t_game *game);
void	move_golem(t_game *game);

void	print_map(t_game *game);
void	print_run_animation(t_game *game);
void	print_idle_animation(t_game *game);
void	print_attack_animation(t_game *game);
void	print_dying_animation(t_game *game);
void	print_barrel(t_game *game);
void	print_enemie(t_game *game);
void	print_necro(t_game *game);
void	print_boss(t_game *game);
void	print_mage(t_game *game, int i);
void	print_dead_mage(t_game *game, int i);
void	print_golem(t_game *game);
void	print_attacking_golem(t_game *game, t_golem *golem);
void	fill_floor(t_game *game);

void	move_mage(t_game *game);
void	move_necro(t_game *game);
void	attack_action(t_game *game);
void	attack_golem(t_game *game);
void	golem_attack_player(t_game *game);
int		boss_see_you(t_game *game, t_boss *boss);
void	check_entity_collision(t_game *game);
void	free_texture(void *mlx, t_sprite *sprite, int i);
void	free_game(t_game *game);
void	free_necro(t_game *game);
void	free_boss(t_game *game);
void	free_golem(t_game *game);

#endif