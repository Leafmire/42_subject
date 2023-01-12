# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/15 06:00:19 by gson              #+#    #+#              #
#    Updated: 2021/11/21 23:27:11 by gson             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client

SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

SRC_DIR = ./src/
INC_DIR = ./include/

SERVER_SRC = minitalk_server.c
CLIENT_SRC = minitalk_client.c

SERVER_SRCS = $(addprefix $(SRC_DIR), $(SERVER_SRC))
CLIENT_SRCS = $(addprefix $(SRC_DIR), $(CLIENT_SRC))

SERVER_OBJS = $(SERVER_SRCS:.c=.o)
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

SERVER_BONUS_SRC = minitalk_server_bonus.c
CLIENT_BONUS_SRC = minitalk_client_bonus.c

SERVER_BONUS_SRCS = $(addprefix $(SRC_DIR), $(SERVER_BONUS_SRC))
CLIENT_BONUS_SRCS = $(addprefix $(SRC_DIR), $(CLIENT_BONUS_SRC))

SERVER_BONUS_OBJS = $(SERVER_SRCS:.c=.o)
CLIENT_BONUS_OBJS = $(CLIENT_SRCS:.c=.o)

LIBS	 = -L./libft -lft

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

all : $(SERVER) $(CLIENT)

$(SERVER) : $(SERVER_OBJS)
		make -C libft
		$(CC) -o $(SERVER) $(SERVER_OBJS) $(LIBS)

$(CLIENT) : $(CLIENT_OBJS)
		make -C libft
		$(CC) -o $(CLIENT) $(CLIENT_OBJS) $(LIBS)

$(SERVER_BONUS) : $(SERVER_BONUS_OBJS)
		make -C libft
		$(CC) -o server $(SERVER_BONUS_OBJS) $(LIBS)

$(CLIENT_BONUS) : $(CLIENT_BONUS_OBJS)
		make -C libft
		$(CC) -o client $(CLIENT_BONUS_OBJS) $(LIBS)

%.o: %.c
		gcc $(CFLAGS) -I $(INC_DIR) -c $< -o $@

bonus : $(SERVER_BONUS) $(CLIENT_BONUS)

clean :
		make -C libft clean
		rm -f $(SERVER_OBJS) $(CLIENT_OBJS) $(SERVER_BONUS_OBJS) $(CLIENT_BONUS_OBJS)

fclean : clean
		make -C libft fclean
		rm -f $(SERVER) $(CLIENT)

re: fclean all

.PHONY : all clean fclean re
