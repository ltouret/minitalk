# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltouret <ltouret@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/31 20:19:58 by ltouret           #+#    #+#              #
#    Updated: 2021/08/31 20:44:36 by ltouret          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server

NAME2 = client

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g# -fsanitize=address -g3

SRC = srcs/server.c srcs/server_utils.c srcs/utils.c

SRC2 = srcs/client.c srcs/client_utils.c srcs/utils.c

OBJ = $(SRC:.c=.o)

OBJ2 = $(SRC2:.c=.o)

all: $(NAME)

$(NAME): ${OBJ} ${OBJ2}
	@echo "\n\033[0;32mCompiling...\033[0m"
	$(CC) ${CFLAGS} $(OBJ) -o $(NAME)
	$(CC) ${CFLAGS} $(OBJ2) -o $(NAME2)
	@echo "\n\033[0;32mDONE!!!\033[0m"

clean:
	@echo "\033[0;31mWipeout..."
	rm -rf $(OBJ)
	rm -rf $(OBJ2)
	@echo "\033[0m"

fclean: clean
	@echo "\033[0;31mRemoving executable..."
	rm -f $(NAME)
	rm -f $(NAME2)
	@echo "\033[0m"

re: fclean all

test: all
	./$(NAME)

.PHONY: all clean fclean re test
