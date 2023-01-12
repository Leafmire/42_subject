# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gson <gson@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/04 16:13:26 by gson              #+#    #+#              #
#    Updated: 2023/01/04 16:13:27 by gson             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_containers
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -g -std=c++98 -fsanitize=address

SRCS = ./main.cpp

.cpp.o :
	$(CXX) $(CXXFLAGS) -c $< -o $(<:.cpp=.o)

OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : clean all

.PHONY: all clean fclean re
