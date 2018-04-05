# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matteo <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/24 23:47:34 by matteo            #+#    #+#              #
#    Updated: 2018/04/05 19:27:05 by matteo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC = srcs/display/display.c\
      srcs/display/displayList.c\
      srcs/display/displayLong.c\
      srcs/display/displayLong2.c\
      srcs/display/displayTotal.c\
      srcs/main/core.c\
      srcs/main/main.c\
      srcs/misc/add_file.c\
      srcs/misc/error.c\
      srcs/misc/getsize.c\
      srcs/misc/mergesort.c\
      srcs/misc/parsing.c\
      srcs/misc/reverse_list.c\
      srcs/misc/showpath.c\
      srcs/misc/sort.c\
      srcs/misc/useful.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra -g

LIBFLAGS = -Llibft -lft

all: $(NAME)

$(NAME): $(OBJ) 
	@make -C libft/
	@gcc $(OBJ) -L libft/ -lft -o $(NAME) 
	@echo "\033[32mCompilation done :)"

clean:
	rm -Rf $(OBJ)

fclean: clean
	rm -Rf $(NAME)

re: fclean all
