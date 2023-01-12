# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/11 16:07:46 by gson              #+#    #+#              #
#    Updated: 2022/07/19 16:46:40 by gson             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	megaphone

CC		=	clang++

CFLAG	=	-Wall -Wextra -Werror -std=c++98

RM		=	rm -f

SRC		=	megaphone.cpp
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