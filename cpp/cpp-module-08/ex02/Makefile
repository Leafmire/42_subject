# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/02 19:15:33 by gson              #+#    #+#              #
#    Updated: 2022/08/10 00:03:26 by gson             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	mutantstack

CXX		=	c++

CXXFLAG	=	-Wall -Wextra -Werror -std=c++98

RM		=	rm -f

SRC		=	main.cpp
OBJ		=	$(SRC:%.cpp=%.o)

#INC	=

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAG) -o $@ $(OBJ)

$(OBJ): %.o: %.cpp
	$(CXX) $(CXXFLAG) -c $< -o $@ 

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re