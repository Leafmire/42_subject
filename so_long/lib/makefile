# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/16 11:59:57 by gson              #+#    #+#              #
#    Updated: 2021/11/21 23:35:45 by gson             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lib_gson.a

CFLAGS = -Wall -Wextra -Werror

PRINTF = ./ft_printf/

GNL = ./get_next_line/

LIBFT = ./libft/

HEADER = $(PRINTF)ft_printf.h $(GNL)get_next_line.h $(LIBFT)libft.h

SRCS_PRINTF = $(PRINTF)ft_createspace.c $(PRINTF)ft_formatone.c \
			  $(PRINTF)ft_formatthree.c $(PRINTF)ft_formattwo.c \
			  $(PRINTF)ft_initspecs.c $(PRINTF)ft_printf.c $(PRINTF)ft_putchar.c \
			  $(PRINTF)ft_putnbr.c $(PRINTF)ft_putnbr_hex.c \
			  $(PRINTF)ft_putstr.c $(PRINTF)ft_strlen.c $(PRINTF)ft_isdigit.c \
			  $(PRINTF)ft_strdup.c

SRCS_GNL = $(GNL)get_next_line.c \
		   $(GNL)get_next_line_utils.c

SRCS_FT = $(LIBFT)ft_putchar_fd.c \
		  $(LIBFT)ft_putendl_fd.c \
		  $(LIBFT)ft_putstr_fd.c \
		  $(LIBFT)ft_putnbr_fd.c \
		  $(LIBFT)ft_strdup.c \
		  $(LIBFT)ft_strlcpy.c \
		  $(LIBFT)ft_strrchr.c \
		  $(LIBFT)ft_strncmp.c

SRCS = $(SRCS_GNL) $(SRCS_FT)

OBJS = $(SRCS_GNL:.c=.o) $(SRCS_FT:.c=.o)

CC = gcc

RM = rm -f

all : $(NAME)

$(NAME) : $(OBJS)
		ar rsc $(NAME) $(OBJS)

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

bonus : all

clean :
		$(RM) $(OBJS)

fclean : clean
		$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
