# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbled <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/15 21:34:02 by nbled             #+#    #+#              #
#    Updated: 2022/10/15 21:34:05 by nbled            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER = server
NAME_CLIENT = client

SRCS_SERVER = main_server.c \
			  ft_putnbr.c \
			  ft_putstr.c
SRCS_CLIENT = main_client.c

OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: ${NAME_SERVER} ${NAME_CLIENT}

${NAME_SERVER}: ${OBJS_SERVER}
	${CC} ${CFLAGS} ${OBJS_SERVER} -o ${NAME_SERVER}

${NAME_CLIENT}: ${OBJS_CLIENT}
	${CC} ${CFLAGS} ${OBJS_CLIENT} -o ${NAME_CLIENT}

clean:
	rm -f ${OBJS_SERVER} ${OBJS_CLIENT}

fclean: clean
	rm -f ${NAME_SERVER} ${NAME_CLIENT}

re: fclean all

.PHONY: all clean fclean re

