# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/11 16:07:46 by gson              #+#    #+#              #
#    Updated: 2022/07/19 16:52:58 by gson             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	phonebook

CC		=	clang++

CFLAG	=	-Wall -Wextra -Werror -std=c++98

RM		=	rm -f

SRC		=	Phonebook.cpp \
			Contact.cpp \
			main.cpp

OBJ		=	$(SRC:%.cpp=%.o)

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