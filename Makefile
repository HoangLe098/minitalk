CC = cc
FLAGS = -Wall -Werror -Wextra

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

all: subsystem $(SERVER_NAME) $(CLIENT_NAME)

subsystem:
	@make -C ./libft all
	@make -C ./printf all

$(SERVER_NAME): $(SER_O)
	$(CC) $(FLAGS) $(SER_SRC) $(PRINTF_INC) $(PRINTF_LIB) $(LIBFT_INC) $(LIBFT_LIB) -o $(SERVER_NAME)
$(CLIENT_NAME): $(CLI_O)
	$(CC) $(FLAGS) $(CLI_SRC) $(PRINTF_INC) $(PRINTF_LIB) $(LIBFT_INC) $(LIBFT_LIB) -o $(CLIENT_NAME)

%.o: %.c
	$(CC) $(FLAGS) $(PRINTF_INC) $(LIBFT_INC) -c $< -o $@

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