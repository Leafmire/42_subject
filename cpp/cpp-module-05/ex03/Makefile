# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/11 16:07:46 by gson              #+#    #+#              #
#    Updated: 2022/07/30 20:57:22 by gson             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	form

CXX		=	c++

CXXFLAG	=	-Wall -Wextra -Werror -std=c++98

RM		=	rm -f

SRC		=	main.cpp Bureaucrat.cpp Form.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp
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