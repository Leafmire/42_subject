# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/11 16:07:46 by gson              #+#    #+#              #
#    Updated: 2022/07/18 20:54:26 by gson             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	zombiehorde

CC		=	g++

CFLAG	=	-Wall -Wextra -Werror

RM		=	rm -f

SRC		=	Zombie.cpp ZombieHorde.cpp main.cpp
OBJ		=	$(SRC:%.cpp=%.o)

#INC	=

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAG) -o $@ $(OBJ)

$(OBJ): %.o: %.cpp
	$(CC) $(CFLAG) -c $< -o $@ 

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re