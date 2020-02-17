# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmakynen <lmakynen@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/19 15:03:59 by lmakynen          #+#    #+#              #
#    Updated: 2020/02/17 19:56:20 by lmakynen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SOURCE = main.c validation.c make_pieces.c ft_square.c ft_make_box.c solver.c
OFILES = $(subst .c,.o,$(SOURCE))

HEADER = ./libft
LIB = -L libft/ -lft

FLAGS = -Wall -Werror -Wextra

.PHONY: all clean fclean re libft

all: $(NAME)

$(NAME): libft
	gcc $(FLAGS) -c -I $(HEADER) $(SOURCE)
	gcc -o $(NAME) $(OFILES) $(LIB)

libft:
	make -C libft/

clean:
	make clean -C libft/
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all
