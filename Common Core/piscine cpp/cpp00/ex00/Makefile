# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbled <nbled@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/30 15:46:08 by nbled             #+#    #+#              #
#    Updated: 2023/08/30 15:49:52 by nbled            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

OBJ_DIR = objs

SRCS = megaphone.cpp

OBJS = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRCS))

CC = c++
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -fsanitize=undefined -fsanitize=leak -std=c++98 -g -I include -MMD -MP

$(NAME): $(OBJS)
	@echo "\033[0;34mCompiling $(NAME)...\033[0m"
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "\033[0;32mCompilation done.\033[0m"

all: $(NAME)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "\033[0;34mCleaning objects...\033[0m"
	rm -rf $(OBJ_DIR)
	@echo "\033[0;32mCleaning done.\033[0m"

fclean: clean
	@echo "\033[0;34mCleaning executable...\033[0m"
	rm -f $(NAME)
	@echo "\033[0;32mCleaning done.\033[0m"

re: fclean all

-include $(OBJS:.o=.d)
.PHONY: all clean fclean re
