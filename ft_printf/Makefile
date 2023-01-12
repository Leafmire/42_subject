# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/19 19:21:53 by gson              #+#    #+#              #
#    Updated: 2021/08/19 19:21:53 by gson             ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

HEADER = ft_printf.h

SRCS = ft_createspace.c ft_formatone.c ft_formatthree.c ft_formattwo.c \
		ft_initspecs.c ft_printf.c ft_putchar.c ft_putnbr.c ft_putnbr_hex.c \
		ft_putstr.c ft_strlen.c ft_isdigit.c ft_strdup.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
		ar rsc $(NAME) $(OBJS)

%.o: %.c
		gcc $(CFLAGS) -c $< -o $@

bonus : all

clean :
		rm -f $(OBJS)

fclean : clean
		rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re