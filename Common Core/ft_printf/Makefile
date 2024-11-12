# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbled <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/11 20:43:17 by nbled             #+#    #+#              #
#    Updated: 2022/07/11 20:43:21 by nbled            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS =	ft_putchar.c \
		ft_putstr.c \
		ft_putptr.c \
		ft_putnbr.c \
		ft_putunsigned.c \
		ft_puthexa.c \
		ft_printf.c

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS}

bonus: ${OBJS} ${B_OBJS}
	ar rcs ${NAME} ${OBJS} ${B_OBJS}

all: ${NAME}

clean:
	rm -f ${OBJS} ${B_OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: bonus all clean fclean re