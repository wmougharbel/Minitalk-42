# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wmoughar <wmoughar@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/23 10:44:08 by wmoughar          #+#    #+#              #
#    Updated: 2023/02/23 10:44:08 by wmoughar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wmoughar <wmoughar@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/23 10:44:08 by wmoughar          #+#    #+#              #
#    Updated: 2023/02/23 10:44:08 by wmoughar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

SOURCES = server.c client.c 

OBJECTS = $(SOURCES:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

$(NAME): server client

all: server client

server: server.o libft printf
	@$(CC) $(CFLAGS) -o $@ $< -LLibft -lft -Lft_printf -lftprintf

client: client.o libft printf
	@$(CC) $(CFLAGS) -o $@ $< -LLibft -lft -Lft_printf -lftprintf

%.o: %.c
	$(CC) -c $(CFLAGS) $?

libft:
	@make -C Libft

printf:
	@make -C ft_printf

clean:
	$(RM) $(OBJECTS)
	@make -C Libft clean
	@make -C ft_printf clean

fclean: clean
	$(RM) server client Libft/libft.a ft_printf/libftprintf.a

re: fclean all

.PHONY: all libft clean fclean re