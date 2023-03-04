# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 16:53:40 by gyoon             #+#    #+#              #
#    Updated: 2023/03/04 20:58:41 by gyoon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
# CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRCS_ERROR	= $(addprefix error/,	raise_error.c)
SRCS_GAME	= $(addprefix game/,	close_game.c		\
									draw_game.c			\
									hook_loop.c			\
									init_game.c)
SRCS_KEY	= $(addprefix key/,		hook_key_press.c	\
									hook_key_release.c	\
									init_key.c)
SRCS_MAP	= $(addprefix map/,		draw_map.c			\
									init_map.c			\
									read_map.c			\
									set_map.c)
SRCS_PLAYER	= $(addprefix player/,	draw_player.c		\
									init_player.c		\
									set_player.c)
SRCS_POINT	= $(addprefix point/,	init_point.c)
SRCS_READ	= $(addprefix read/,	read_assets.c		\
									read_image.c)
SRCS_MAIN	= main.c

SRCS = $(addprefix src/,	$(SRCS_ERROR)	\
							$(SRCS_GAME)	\
							$(SRCS_KEY)		\
							$(SRCS_MAP)		\
							$(SRCS_PLAYER)	\
							$(SRCS_POINT)	\
							$(SRCS_READ)	\
							$(SRCS_MAIN))
OBJS = $(SRCS:.c=.o)

B_SRCS = ${SRCS:.c=_bonus.c}
B_OBJS = ${OBJS:.o=_bonus.o}

MINILIBX = ./minilibx
MLX = mlx
LIBFT = libft/libft.a

INCLUDE = ./include

ifdef BONUS
    F_OBJS = $(B_OBJS)
else
    F_OBJS = $(OBJS)
endif

all : $(NAME)

$(NAME) : $(LIBFT) $(F_OBJS)
	$(CC) -L$(MINILIBX) -L./libft -framework OpenGL -framework Appkit -lz $(SRCS) -lmlx -lft -I $(INCLUDE) -o $@

bonus : 
	make BONUS=1 all

$(LIBFT) :
	make -C libft

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDE)

clean :
	$(RM) $(OBJS)
	$(RM) $(B_OBJS)
	make -C libft clean

fclean :
	make clean
	$(RM) $(NAME)
	make -C libft fclean

re :
	make fclean
	make all

.PHONY : all bonus clean fclean re
