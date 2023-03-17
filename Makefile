# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 16:53:40 by gyoon             #+#    #+#              #
#    Updated: 2023/03/17 16:11:36 by gyoon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
# CFLAGS = -Wall -Wextra -Werror
LEAKFLAGS = -g3 -fsanitize=address
RM = rm -rf

SRCS_ASSET			= $(addprefix asset/,		read_assets.c)
SRCS_CHARACTER		= $(addprefix character/,	is_overlapped.c)
SRCS_COLLECTIBLE	= $(addprefix collectible/,	draw_collectibles.c				\
												get_remaining_collectibles.c	\
												update_collectibles.c			\
												set_collectibles.c)
SRCS_ENEMY			= $(addprefix enemy/,		draw_enemy.c		\
												init_enemy.c		\
												kill_enemy.c		\
												move_enemy.c		\
												set_enemy.c			\
												update_enemy_a.c	\
												update_enemy_pos.c	\
												update_enemy_v.c)
SRCS_ERROR			= $(addprefix error/,		raise_error.c)
SRCS_EXIT			= $(addprefix exit/,		draw_exit.c			\
												init_exit.c			\
												move_exit.c			\
												set_exit.c			\
												update_exit_a.c		\
												update_exit_pos.c	\
												update_exit_v.c)
SRCS_GAME			= $(addprefix game/,		check_game_clear.c	\
												close_game.c		\
												draw_game.c			\
												init_game.c			\
												restart_game.c		\
												run_game.c)			
SRCS_IMAGE			= $(addprefix image/,		read_image.c)
SRCS_KEY			= $(addprefix key/,			hook_key_press.c	\
												hook_key_release.c	\
												init_key.c)
SRCS_MAP			= $(addprefix map/,			$(SRCS_VALIDATION)	\
												draw_map.c			\
												init_map.c			\
												modify_map.c		\
												read_map.c			\
												set_map.c			\
												validate_map_path.c	\
												validate_map.c)
SRCS_VALIDATION		= $(addprefix validation/,	has_proper_char.c	\
												has_valid_route.c	\
												is_playable.c		\
												is_rectangle.c		\
												is_surrounded.c)
SRCS_PLAYER			= $(addprefix player/,		$(SRCS_MOVEMENT)	\
												draw_player.c		\
												find_player.c		\
												init_player.c		\
												kill_player.c		\
												move_player.c		\
												set_player.c		\
												update_player_a.c	\
												update_player_pos.c	\
												update_player_v.c)
SRCS_MOVEMENT		= $(addprefix movement/,	display_movement.c	\
												has_movement.c)
SRCS_POINT			= $(addprefix point/,		init_point.c)
SRCS_MAIN			= main.c

SRCS				= $(addprefix src/,	$(SRCS_ASSET)		\
										$(SRCS_CHARACTER)	\
										$(SRCS_COLLECTIBLE)	\
										$(SRCS_ENEMY)		\
										$(SRCS_ERROR)		\
										$(SRCS_EXIT)		\
										$(SRCS_GAME)		\
										$(SRCS_IMAGE)		\
										$(SRCS_KEY)			\
										$(SRCS_MAP)			\
										$(SRCS_PLAYER)		\
										$(SRCS_POINT)		\
										$(SRCS_MAIN))
OBJS = $(SRCS:.c=.o)

B_SRCS = ${SRCS:.c=_bonus.c}
B_OBJS = ${OBJS:.o=_bonus.o}

MLX_PATH = ./minilibx
FT_PATH = ./libft
MLX = ./minilibx/libmlx.a
LIBFT = libft/libft.a

INCLUDE = ./include

ifdef BONUS
    F_OBJS = $(B_OBJS)
else
    F_OBJS = $(OBJS)
endif

all : $(NAME)

$(NAME) : $(LIBFT) $(MLX) $(F_OBJS)
	$(CC) $(LEAKFLAGS) -L$(MLX_PATH) -L$(FT_PATH) -framework OpenGL -framework Appkit -lz $(SRCS) -lmlx -lft -I $(INCLUDE) -o $@

bonus : 
	make BONUS=1 all

$(LIBFT) :
	make -C libft

$(MLX) :
	make -C minilibx

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDE)

clean :
	$(RM) $(OBJS)
	$(RM) $(B_OBJS)
	make -C libft clean
	make -C minilibx clean

fclean :
	make clean
	$(RM) $(NAME)
	make -C libft fclean

re :
	make fclean
	make all

.PHONY : all bonus clean fclean re
