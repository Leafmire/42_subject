# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gson <gson@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/01 06:00:19 by gson              #+#    #+#              #
#    Updated: 2022/09/15 16:46:00 by gson             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
NAME_BONUS = cub3d_bonus

SRCS = main.c \
	   ./lib/gnl/get_next_line.c \
	   ./lib/gnl/get_next_line_utils.c \
	   ./src/check_map_valid.c \
	   ./src/error.c \
	   ./src/init_data.c \
	   ./src/init_map.c \
	   ./src/init_player.c \
	   ./src/map_check_util.c \
	   ./src/init_cub_file_option.c \
	   ./src/load_cub_file_option.c \
	   ./src/minimap.c \
	   ./src/util.c \
	   ./src/check_wall.c \
	   ./src/control_player.c \
	   ./src/draw_map.c \
	   ./src/rays.c \
	   ./src/dda.c \
	   ./src/free_all.c \
	   ./src/render_wall.c \
	   ./src/hook.c

SRCS_BONUS = main_bonus.c \
	   ./lib/gnl/get_next_line.c \
	   ./lib/gnl/get_next_line_utils.c \
	   ./src_bonus/check_map_valid_bonus.c \
	   ./src_bonus/error_bonus.c \
	   ./src_bonus/init_data_bonus.c \
	   ./src_bonus/init_map_bonus.c \
	   ./src_bonus/init_player_bonus.c \
	   ./src_bonus/map_check_util_bonus.c \
	   ./src_bonus/init_cub_file_option_bonus.c \
	   ./src_bonus/load_cub_file_option_bonus.c \
	   ./src_bonus/minimap_bonus.c \
	   ./src_bonus/util_bonus.c \
	   ./src_bonus/check_wall_bonus.c \
	   ./src_bonus/control_player_bonus.c \
	   ./src_bonus/draw_map_bonus.c \
	   ./src_bonus/rays_bonus.c \
	   ./src_bonus/dda_bonus.c \
	   ./src_bonus/free_all_bonus.c \
	   ./src_bonus/render_wall_bonus.c \
	   ./src_bonus/hook_bonus.c

LIBFT = ./lib/libft
LIBFT_LIB = ./lib/libft/libft.a
MLX42 = MLX42
MLX42_LIB = MLX42/libmlx42.a
INC_DIR	=	include

CC = gcc
CFLAGS = -Wall -Wextra -Werror -O3 -g

ifeq ($(shell uname), Linux)
LIBFLAGS = -ldl -lglfw -lm -lpthread
else
LIBFLAGS = -lglfw -L"$(HOME)/.brew/opt/glfw/lib/"
endif

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(INC_DIR)

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all : $(NAME)

bonus : $(NAME_BONUS)

$(NAME) : $(OBJS)
	make all -C $(LIBFT)
	make all -C $(MLX42)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) $(MLX42_LIB) -I $(INC_DIR) $(LIBFLAGS) -o $(NAME)

$(NAME_BONUS) : $(OBJS_BONUS)
	make all -C $(LIBFT)
	make all -C $(MLX42)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT_LIB) $(MLX42_LIB) -I $(INC_DIR) $(LIBFLAGS) -o $(NAME_BONUS)

clean :
	rm -f $(OBJS)
	rm -f $(OBJS_BONUS)
	make clean -C $(LIBFT)
	make clean -C $(MLX42)

fclean : clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)
	make fclean -C $(LIBFT)
	make fclean -C $(MLX42)

re : clean all

.PHONY: all clean fclean re bonus
