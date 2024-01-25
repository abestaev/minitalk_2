# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albestae <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/25 14:00:37 by albestae          #+#    #+#              #
#    Updated: 2024/01/25 16:48:09 by albestae         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
SERVER_NAME = server
CLIENT_NAME = client

SERVER_SRC = src/utils.c src/server.c
CLIENT_SRC = src/utils.c src/client.c

SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

all: $(SERVER_NAME) $(CLIENT_NAME)

$(SERVER_NAME): $(SERVER_OBJ)
		$(CC) -o $(SERVER_NAME) $(SERVER_SRC) $(CFLAGS)

$(CLIENT_NAME): $(CLIENT_OBJ)
		$(CC) -o $(CLIENT_NAME) $(CLIENT_SRC) $(CFLAGS)
clean:
	rm -f $(SERVER_OBJ) $(CLIENT_OBJ)

fclean: clean
	rm -f $(SERVER_NAME) $(CLIENT_NAME)

re: fclean all

.PHONY: all clean fclean re
