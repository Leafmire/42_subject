# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gson <gson@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/27 15:59:46 by gson              #+#    #+#              #
#    Updated: 2022/09/29 01:31:57 by gson             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DB_DIR=/Users/gson/data/db
WEB_DIR=/Users/gson/data/web

all : build

build:
	@mkdir -p $(DB_DIR)
	@mkdir -p $(WEB_DIR)
	@docker-compose -f ./srcs/docker-compose.yml up -d --build

clean:
	@docker-compose -f ./srcs/docker-compose.yml down
	@docker volume rm $$(docker volume ls -q)
	@docker rmi -f $$(docker images)

vclean:
	@rm -rf $(DB_DIR)
	@rm -rf $(WEB_DIR)

.PHONY: all build clean vclean