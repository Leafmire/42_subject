# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/02 19:15:33 by gson              #+#    #+#              #
#    Updated: 2022/08/06 19:51:22 by gson             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	base

CXX		=	c++

CXXFLAG	=	-Wall -Wextra -Werror -std=c++98

RM		=	rm -f

SRC		=	main.cpp Base.cpp
OBJ		=	$(SRC:%.cpp=%.o)

#INC	=

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAG) -o $@ $(OBJ)

$(OBJ): %.o: %.cpp
	$(CXX) $(CXXFLAG) -c $< -o $@ 

leaks: $(NAME)
	-leaks -atExit -- ./$(NAME) | grep LEAK:

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re