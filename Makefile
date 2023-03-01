# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 01:40:28 by pbergero          #+#    #+#              #
#    Updated: 2023/02/26 20:15:58 by pbergero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#------------------------------------------------------------------------------#
#                                  GENERICS                                    #
#------------------------------------------------------------------------------#

# Special variables
DEFAULT_GOAL: all
.DELETE_ON_ERROR: $(NAME)
.PHONY: all bonus clean fclean re
# 'HIDE = @' will hide all terminal output from Make
HIDE =


#------------------------------------------------------------------------------#
#                                VARIABLES                                     #
#------------------------------------------------------------------------------#

# Compiler and flags
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra -Imlx
RM		=	rm -f
MAKE	=	make

# Output file name
NAME	=	so_long

# Sources are all .c files
SRCS	=	./src/so_long.c \
			./src/read_map.c \
			./src/texture.c \
			./src/move.c \
			./src/entity.c\
			./src/entity_utils.c\
			./src/entity_utils2.c\
			./src/collision.c\
			./src/player_texture.c\
			./src/player_animation.c\
			./src/player_texture2.c\
			./src/tiles_texture.c\
			./src/barrel_texture.c\
			./src/attack.c\
			./src/mage_texture.c\
			./src/mage_animation.c\
			./src/free_game.c\
			./src/free_game2.c\
			./src/necro_animation.c\
			./src/necro_texture.c\
			./src/boss_texture.c\
			./src/boss_animation.c\
			./src/boss_fight.c\
			./src/boss_texture2.c\
			./src/golem_texture.c\
			./src/golem_texture2.c\
			./src/golem_animation.c\
			./src/golem_animation2.c\
			./src/golem_fight.c\
			./src/str_to_screen.c\
			./src/flood_fill.c\
			./src/check_up.c\
			
# Objects are all .o files
OBJS	=	$(SRCS:.c=.o)

LIBFT	=	libft/libft.a

MAP		=	./maps/map02.ber
#------------------------------------------------------------------------------#
#                                 TARGETS                                      #
#------------------------------------------------------------------------------#

all: $(NAME)

# Generates output file
$(NAME): $(OBJS) $(LIBFT)
	$(HIDE)$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit $(LIBFT) -o $@ $^

$(LIBFT):
	$(MAKE) -C libft
# Removes objects
clean:
	$(HIDE)$(RM) $(OBJS)
	$(MAKE) -C libft clean

# Removes objects and executables
fclean: clean
	$(HIDE)$(RM) $(NAME)
	$(MAKE) -C libft fclean

play: $(NAME)
	./so_long $(MAP)
# Removes objects and executables and remakes
re: fclean all

leaks: $(NAME)
	leaks -atExit -- ./so_long $(MAP)