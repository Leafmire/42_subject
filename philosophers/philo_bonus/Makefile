# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/16 04:02:56 by gson              #+#    #+#              #
#    Updated: 2022/04/20 06:07:38 by gson             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

SRC_DIR = ./src/
INC_DIR = ./include/

SRC = main.c init_dinner.c round_robin.c circulation.c util.c util2.c error.c 

SRCS = $(addprefix $(SRC_DIR), $(SRC))
OBJS = $(SRCS:.c=.o)

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS) $(INC_DIR)
		$(CC) $(CFLAGS) -o $(NAME) -I $(INC_DIR) $(OBJS) -lpthread

clean : 
		$(RM) $(OBJS)

fclean : clean
		$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
