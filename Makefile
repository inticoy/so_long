# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 16:53:40 by gyoon             #+#    #+#              #
#    Updated: 2023/03/07 21:41:57 by gyoon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
# CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRCS_COLLECTIBLE	= $(addprefix collectible/,	draw_collectibles.c	\
												set_collectibles.c)
SRCS_ENEMY			= $(addprefix enemy/,		draw_enemy.c		\
												init_enemy.c		\
												move_enemy.c		\
												set_enemy.c)
SRCS_ERROR			= $(addprefix error/,		raise_error.c)
SRCS_EXIT			= $(addprefix exit/,		draw_exit.c)
SRCS_GAME			= $(addprefix game/,		close_game.c		\
												draw_game.c			\
												hook_loop.c			\
												init_game.c)
SRCS_KEY			= $(addprefix key/,			hook_key_press.c	\
												hook_key_release.c	\
												init_key.c)
SRCS_MAP			= $(addprefix map/,			draw_map.c			\
												init_map.c			\
												read_map.c			\
												set_map.c)
SRCS_PLAYER			= $(addprefix player/,		calc_player_a.c		\
												calc_player_pos.c	\
												calc_player_v.c		\
												draw_player.c		\
												init_player.c		\
												move_player.c		\
												set_player.c)
SRCS_POINT			= $(addprefix point/,		init_point.c)
SRCS_READ			= $(addprefix read/,		read_assets.c		\
												read_image.c)
SRCS_MAIN			= main.c

SRCS				= $(addprefix src/,	$(SRCS_COLLECTIBLE)	\
										$(SRCS_ENEMY)		\
										$(SRCS_ERROR)		\
										$(SRCS_EXIT)		\
										$(SRCS_GAME)		\
										$(SRCS_KEY)			\
										$(SRCS_MAP)			\
										$(SRCS_PLAYER)		\
										$(SRCS_POINT)		\
										$(SRCS_READ)		\
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
	$(CC) -L$(MLX_PATH) -L$(FT_PATH) -framework OpenGL -framework Appkit -lz $(SRCS) -lmlx -lft -I $(INCLUDE) -o $@

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
