# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebakirog <ebakirog@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/07 18:38:44 by ebakirog          #+#    #+#              #
#    Updated: 2023/10/07 23:46:04 by ebakirog         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= minitalk
SERVER 			= server
CLIENT 			= client

SERVER_SOURCE	= server.c
CLIENT_SOURCE	= client.c
PRINTF			= ft_printf.a

CC				= gcc
FLAGS			= -Wall -Wextra -Werror
RM				= rm -rf

all: $(NAME)

$(NAME): $(SERVER) $(CLIENT)

$(SERVER):
	$(CC) $(FLAGS) $(SERVER_SOURCE) $(PRINTF) -o $(SERVER)

$(CLIENT):
	$(CC) $(FLAGS) $(CLIENT_SOURCE) $(PRINTF) -o $(CLIENT)

clean:
	$(RM) $(SERVER) $(CLIENT)

fclean:
	$(RM) $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re