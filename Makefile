# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arobion <arobion@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/11 18:20:34 by arobion           #+#    #+#              #
#    Updated: 2018/05/12 17:17:30 by nkamolba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g3

NAME = hotrace

SRC =	hash_table.c \
		gnl.c \
		string.c \
		store.c \
		search.c \
		write.c \
		free_table.c

OBJ = $(SRC:.c=.o)

INCLUDES = hotrace.h

RED = \033[31m
GREEN = \033[32m
END = \033[0m

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@echo "$(GREEN)HOTRACE READY$(END)"
	
%.o: %.c
	$(CC) -c $(CFLAGS) -I $(INCLUDES) -o $@ -c $<

clean:
	/bin/rm -f $(OBJ)
	@echo "$(RED)HOTRACE OBJECTS REMOVE$(END)"

fclean: clean
	/bin/rm -f $(NAME)
	@echo "$(RED)HOTRACE REMOVE$(END)"

re: 
	make fclean
	make all

.PHONY: all
