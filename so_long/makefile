# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/15 06:00:19 by gson              #+#    #+#              #
#    Updated: 2021/11/22 06:23:29 by gson             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = main.c  mlx_util.c read_map.c init_map.c init_vars.c set_image.c \
	  draw_tile.c draw_image.c put_goal.c check_map.c put_player.c \
	  update_player.c update_collect.c error.c manage_list.c \
	  check_complete.c get_ext.c

INCS_DIR	= ./include/
SRCS_DIR	= ./src/
MLX_DIR_MAC	= ./minilibx/
MLX_DIR_LINUX	= ./minilibx_linux/
MLX_DIR_MMS	= ./minilibx_mms/
LIB_DIR		= ./lib/

LIB_NAME	= lib_gson.a
INCS		= -I include

SRCS		=	$(addprefix $(SRCS_DIR), $(SRC))
LIBS		=	$(addprefix $(LIB_DIR), $(LIB_NAME))
OBJS = ${SRCS:.c=.o}

OBJS_B = ${SRCS_B:.c=.o}


CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

MACL	= -lmlx -framework OpenGL -framework Appkit -Imlx
LINUXL = -lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
MMSL = -lmlx_mms -L/usr/lib -Imlx_mms -lXext -lX11 -lm -lz

.c.o:
	${CC} ${CFLAGS} -I $(INCS_DIR) -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
	make -C $(LIB_DIR)
	make -C $(MLX_DIR_MAC)
	$(CC) -o $(NAME) $(OBJS) -L $(LIB_DIR) -l_gson -I $(INCS_DIR) -L $(MLX_DIR_MAC) $(MACL)

all: ${NAME}

bonus: ${OBJS_B}
	ar rcs ${NAME} ${OBJS_B}

clean:
	make -C $(LIB_DIR) clean
	make -C $(MLX_DIR_MAC) clean
	${RM} ${OBJS} ${OBJS_B}

fclean: clean
	make -C $(LIB_DIR) fclean
	${RM} ${NAME}

re: fclean all

.PHONY : all clean fclean re
