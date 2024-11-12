# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbled <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/04 02:23:12 by nbled             #+#    #+#              #
#    Updated: 2022/09/04 02:23:16 by nbled            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS =	main.c \
		push_swap.c \
		push_swap_sort_two.c \
		push_swap_sort_three.c \
		push_swap_sort_four.c \
		push_swap_sort_five.c \
		push_swap_sort_under_sixteen.c \
		true_push_swap.c \
		push_swap_presort.c \
		push_swap_parsing.c \
		ft_lstnew.c \
		ft_lstadd_back.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstclear.c \
		push_swap_condition.c \
		ft_putstr.c \
		push.c \
		swap.c \
		rotate.c \
		reverse_rotate.c \
		ft_strncmp.c \
		ft_atoi.c \
		ft_strlen.c \

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

bonus: ${OBJS} ${B_OBJS}
	${CC} ${CFLAGS} ${OBJS} ${B_OBJS} -o ${NAME} 

all: ${NAME}

clean:
	rm -f ${OBJS} ${B_OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

test3:	$(NAME)    
			$(eval ARG = $(shell shuf -i 0-100 -n 3))
			./push_swap $(ARG) | ./checker_linux $(ARG)
			@echo -n "Nombre d'opérations : "
			@./push_swap $(ARG) | wc -l

test5:	$(NAME)    
			$(eval ARG = $(shell shuf -i 0-5000 -n 5))
			./push_swap $(ARG) | ./checker_linux $(ARG)
			@echo -n "Nombre d'opérations : "
			@./push_swap $(ARG) | wc -l

test100:	$(NAME)    
			$(eval ARG = $(shell shuf -i 0-100 -n 100))
			./push_swap $(ARG) | ./checker_linux $(ARG)
			@echo -n "Nombre d'opérations : "
			@./push_swap $(ARG) | wc -l

test500:	$(NAME)    
			$(eval ARG = $(shell shuf -i 0-5000 -n 500))
			./push_swap $(ARG) | ./checker_linux $(ARG)
			@echo -n "Nombre d'opérations : "
			@./push_swap $(ARG) | wc -l

.PHONY: bonus all clean fclean re