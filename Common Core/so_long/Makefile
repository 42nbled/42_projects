# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbled <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/02 16:04:15 by nbled             #+#    #+#              #
#    Updated: 2022/11/13 14:58:12 by nbled            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS =	so_long.c \
		image_init.c \
		read_map.c \
		print_map.c \
		print_player.c \
		hook.c \
		ft_close.c \
		parsing/map_parsing.c \
		parsing/is_rectangular.c \
		parsing/is_surrounded.c \
		parsing/has_enough.c \
		parsing/map_content.c \
		parsing/map_composition.c \
		parsing/flood_file.c \
		utils/ft_putstr.c \
		utils/ft_putnbr.c \
		utils/ft_split.c \
		utils/get_next_line.c \
		utils/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

# /* ~~~~~~~ INCLUDING MINILIBX ~~~~~~~ */
MLX_DIR = minilibx-linux
MLX_MAKE = Makefile
MLX_PATH = ${MLX_DIR}/libmlx.a

# /* ~~~~~~~ COMPILING INFO ~~~~~~~ */
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -Iminilibx-linux
MFLAGS = $(MLX_PATH) -lXext -lX11

$(NAME): $(OBJS) $(MLX_PATH)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MFLAGS) 

$(MLX_PATH):
	make -C ${MLX_DIR}

all: ${NAME}

clean:
	make clean -C ${MLX_DIR}
	rm -f ${OBJS} ${B_OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: bonus all clean fclean re
