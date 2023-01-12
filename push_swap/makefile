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

NAME = push_swap

SRC_DIR = ./src/

INC_DIR = ./include/

SRC = calculate.c check_input.c ft_atoi.c ft_isdigit.c ft_putstr_fd.c \
		ft_strlen.c push_swap.c sort_small.c sort.c stack_edit.c stack_util.c \
		stack_util2.c ft_split.c ft_strchr.c check_range.c three_case_ab.c \
		three_case_ba.c

SRCS = $(addprefix $(SRC_DIR), $(SRC))

OBJS = $(SRCS:.c=.o)

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -g

$(NAME) : $(OBJS)
		$(CC) -o $(NAME) $(OBJS)

%.o: %.c
		gcc $(CFLAGS) -I $(INC_DIR) -c $< -o $@

all : $(NAME)

clean :
		rm -f $(OBJS)

fclean : clean
		rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
