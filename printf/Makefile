# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hoale <hoale@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 18:21:24 by hoale             #+#    #+#              #
#    Updated: 2025/02/13 19:02:17 by hoale            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c libft.c ft.c conv_char.c conv_dec.c conv_hex.c
OBJ = $(SRCS:.c=.o)
NAME = libftprintf.a
%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<
all: $(NAME)
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
	@ranlib $(NAME)
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all
