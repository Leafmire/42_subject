# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/25 20:21:28 by gson              #+#    #+#              #
#    Updated: 2022/02/25 20:29:29 by gson             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

INC = ../include/libft.h

SRCS = ft_bzero.c ft_memset.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
		ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcat.c ft_strncmp.c \
		ft_strchr.c ft_strrchr.c ft_strlcpy.c ft_strnstr.c ft_isdigit.c \
		ft_isalpha.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_atoi.c \
		ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c \
		ft_strtrim.c ft_strjoin.c ft_split.c ft_itoa.c ft_strmapi.c \
		ft_putchar_fd.c ft_putendl_fd.c ft_putstr_fd.c ft_putnbr_fd.c

OBJS = ${SRCS:.c=.o}

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

%.o: %.c $(INC)
		$(CC) $(CFLAGS) -I ../include -c $< -o $@	

$(NAME): ${OBJS}
	ar rcs ${NAME} ${OBJS}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all
