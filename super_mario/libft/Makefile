# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 16:44:08 by gyoon             #+#    #+#              #
#    Updated: 2023/01/25 22:15:26 by gyoon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
AR = ar
RM = rm -rf

ARFLAGS = -rcs
CFLAGS = -Wall -Wextra -Werror

SRCS = $(addprefix src/, ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
		ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
		ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
		ft_atoi.c ft_calloc.c ft_strdup.c \
		ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
		ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
		ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
		get_next_line.c get_next_line_utils.c \
		ft_printf.c \
		convert_padding.c convert_precision.c convert_prefix.c convert_sign.c convert_space.c \
		init_flag.c need_padding.c need_precision.c need_prefix.c need_sign.c need_space.c update_flag.c \
		get_formatf.c init_format.c is_num_format.c is_str_format.c \
		ft_tstrjoin.c get_tstr_auto.c get_tstr.c get_tstrf.c \
		ft_ctoa.c ft_ptoa.c ft_utoa.c ft_vtoa.c ft_xtoa.c \
		ft_free_s.c ft_strtoupper.c)
		
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I include

clean :
	$(RM) $(OBJS)

fclean :
	make clean
	$(RM) $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re .c.o