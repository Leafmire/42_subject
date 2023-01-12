# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gson <gson@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/11 16:07:46 by gson              #+#    #+#              #
#    Updated: 2022/08/01 17:37:47 by gson             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	claptrap

CXX		=	c++

CXXFLAG	=	-Wall -Wextra -Werror -std=c++98

RM		=	rm -f

SRC		=	main.cpp ClapTrap.cpp
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