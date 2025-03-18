# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hoale <hoale@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/13 13:18:21 by hoale             #+#    #+#              #
#    Updated: 2025/03/18 11:01:41 by hoale            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Werror -Wextra

LIBFT = ./libft/libft.a
PRINTF = ./printf/libftprintf.a

PRINTF_INC	= -I ./printf
PRINTF_LIB	= -L ./printf -lftprintf

LIBFT_INC	= -I ./libft
LIBFT_LIB	= -L ./libft -lft

SER_SRC = server.c
CLI_SRC = client.c

SER_O = $(SER_SRC:.c=.o)
CLI_O = $(CLI_SRC:.c=.o)

SERVER_NAME = server
CLIENT_NAME = client

all: $(SERVER_NAME) $(CLIENT_NAME)

$(LIBFT):
	@make -C ./libft all
$(PRINTF):
	@make -C ./printf all

$(SERVER_NAME): $(LIBFT) $(PRINTF) $(SER_O)
	$(CC) $(FLAGS) $(SER_SRC) $(PRINTF_INC) $(PRINTF_LIB) $(LIBFT_INC) $(LIBFT_LIB) -o $(SERVER_NAME)
	
$(CLIENT_NAME): $(LIBFT) $(PRINTF) $(CLI_O)
	$(CC) $(FLAGS) $(CLI_SRC) $(PRINTF_INC) $(PRINTF_LIB) $(LIBFT_INC) $(LIBFT_LIB) -o $(CLIENT_NAME)

clean:
	make -C libft/ clean
	make -C printf/ clean
	rm -f $(SER_O) $(CLI_O)

tidy: all clean

fclean:	clean
		make -C libft/ fclean
		make -C printf/ fclean
		rm -f $(SERVER_NAME) $(CLIENT_NAME)

re: fclean all

.PHONY: all clean tidy fclean re
