# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 16:53:40 by gyoon             #+#    #+#              #
#    Updated: 2023/03/22 23:05:58 by gyoon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

# **************************************************************************** #
#                                                                              #
#    Options                                                                   #
#                                                                              #
# **************************************************************************** #

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -rf

ifeq ($(shell uname -p), arm)
	ARM	= 1
else
	ARM	= 0
endif

# **************************************************************************** #
#                                                                              #
#    Source Files                                                              #
#                                                                              #
# **************************************************************************** #

asset		= $(addprefix asset/,		read_assets.c)
character	= $(addprefix character/,	is_overlapped.c)
collectible	= $(addprefix collectible/,	draw_collectibles.c				\
										get_remaining_collectibles.c	\
										update_collectibles.c			\
										set_collectibles.c)
enemy		= $(addprefix enemy/,		draw_enemy.c		\
										init_enemy.c		\
										kill_enemy.c		\
										move_enemy.c		\
										set_enemy.c			\
										update_enemy_a.c	\
										update_enemy_pos.c	\
										update_enemy_v.c)
error		= $(addprefix error/,		raise_error.c)
exit		= $(addprefix exit/,		draw_exit.c			\
										init_exit.c			\
										move_exit.c			\
										set_exit.c			\
										update_exit_a.c		\
										update_exit_pos.c	\
										update_exit_v.c)
game		= $(addprefix game/,		check_game_clear.c	\
										clear_game.c		\
										close_game.c		\
										draw_game.c			\
										init_game.c			\
										restart_game.c		\
										run_game.c)			
image		= $(addprefix image/,		read_image.c)
key			= $(addprefix key/,			hook_key_press.c	\
										hook_key_release.c	\
										init_key.c)
map			= $(addprefix map/,			$(map_data)	\
										$(validation)	\
										del_map.c			\
										draw_map.c			\
										init_map.c			\
										modify_map.c		\
										read_map.c			\
										set_map.c			\
										validate_map_path.c	\
										validate_map.c)
map_data	= $(addprefix data/,		set_map_data.c		\
										update_map_data.c)
validation	= $(addprefix validation/,	has_proper_char.c	\
										has_valid_route.c	\
										is_playable.c		\
										is_rectangle.c		\
										is_surrounded.c)
player		= $(addprefix player/,		$(movement)	\
										draw_player.c		\
										find_player.c		\
										init_player.c		\
										kill_player.c		\
										move_player.c		\
										set_player.c		\
										update_player_a.c	\
										update_player_pos.c	\
										update_player_v.c)
movement	= $(addprefix movement/,	display_movement.c	\
										has_movement.c)
point		= $(addprefix point/,		init_point.c)
main		= main.c

SRCS		= $(addprefix src/,			$(asset)		\
										$(character)	\
										$(collectible)	\
										$(enemy)		\
										$(error)		\
										$(exit)			\
										$(game)			\
										$(image)		\
										$(key)			\
										$(map)			\
										$(player)		\
										$(point)		\
										$(main))

SRCS_BONUS	= $(addprefix src_bonus/,	$(asset)		\
										$(character)	\
										$(collectible)	\
										$(enemy)		\
										$(error)		\
										$(exit)			\
										$(game)			\
										$(image)		\
										$(key)			\
										$(map)			\
										$(player)		\
										$(point)		\
										$(main))

B_OBJS = ${SRCS_BONUS:.c=_bonus.o}

ifdef BONUS
	OBJS 	= ${SRCS_BONUS:.c=_bonus.o}
else
    OBJS 	= $(SRCS:.c=.o)
endif

MLX_PATH	= ./minilibx
FT_PATH		= ./libft
MLX			= ./minilibx/libmlx.a
LIBFT		= libft/libft.a

INCLUDE		= ./include

# **************************************************************************** #
#                                                                              #
#    Progress                                                                  #
#                                                                              #
# **************************************************************************** #


num_file	= $(shell echo $(SRCS) | tr ' ' '\n' | wc -w)
cnt			:= 0
bar_done	= '🟩🟩🟩🟩🟩🟩🟩🟩🟩🟩🟩🟩🟩🟩🟩🟩'
bar_ready	= '⬜️⬜️⬜️⬜️⬜️⬜️⬜️⬜️⬜️⬜️⬜️⬜️⬜️⬜️⬜️⬜️'

#			COLOR
red			= \e[1;31m
grn			= \e[1;32m
yel			= \e[1;33m
blu			= \e[1;34m
mag			= \e[1;35m
cyn			= \e[1;36m
bold		= \e[1;37m
end			= \e[0m

ifdef BONUS
	version = "bonus version"
else
	version = "mandatory version"
endif

# **************************************************************************** #
#                                                                              #
#    Executable Section                                                        #
#                                                                              #
# **************************************************************************** #

all : $(NAME)

$(NAME) : $(LIBFT) $(MLX) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS)\
		-L$(MLX_PATH) 		\
		-L$(FT_PATH) 		\
		-lmlx -lft			\
		-framework OpenGL	\
 		-framework Appkit 	\
		-D ARM=$(ARM)		\
		-I $(INCLUDE) -o $@
	@printf "\rCompiling source files... "
	@printf "%.$(shell printf "%d" 64)s" $(bar_done)
	@printf "%7.2f%%\n" 100
	@printf "🎮 Now you can play ${bold}Super Mario Bros.${end}"
	@printf " (%s)\n" $(version)

bonus : 
	@make BONUS=1 all

$(LIBFT) :
	@printf "Build ${bold}[LIBFT]${end}\n"
	@make -C libft -s
	@printf "${grn}BUILD SUCCESSFUL${end}\n\n"

$(MLX) :
	@printf "Build ${bold}[MINILIBX]${end}\n"
	@make -C minilibx -s
	@printf "${grn}BUILD SUCCESSFUL${end}\n\n"

%.o : %.c
	@$(eval cnt=$(shell printf $$(($(cnt)+1))))
	@$(eval rate_hex=$(shell echo "scale=2; ($(cnt) / $(num_file)) * 16" | bc))
	@$(eval len=$(shell printf "%.0f\n" $(rate_hex)))
	@$(eval len_done=$(shell echo "scale=0; $(len) * 4" | bc))
	@$(eval len_ready=$(shell echo "scale=0; 96 - ($(len_done) / 4) * 6" | bc))
	@$(eval percent=$(shell echo "scale=4; ($(cnt) / $(num_file)) * 100" | bc))
	@printf "\rCompiling source files... "
	@printf "%.$(shell printf "%d" $(len_done))s" $(bar_done)
	@printf "%.$(shell printf "%d" $(len_ready))s" $(bar_ready)
	@printf "%7.2f%%" $(percent)
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDE)

clean :
	@$(RM) $(OBJS)
	@$(RM) $(B_OBJS)
	@make -C libft clean
	@make -C minilibx clean
	@printf "make clean ${bold}Super Mario Bros.${end}\n"

fclean :
	@make clean
	@$(RM) $(NAME)
	@make -C libft fclean
	@printf "make fclean ${bold}Super Mario Bros.${end}\n"

re :
	@make fclean
	@printf "\n"
	@make all

.PHONY : all bonus clean fclean re
