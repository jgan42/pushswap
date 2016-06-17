# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgan <jgan@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/28 21:57:41 by jgan              #+#    #+#              #
#    Updated: 2016/01/13 16:37:33 by jgan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Wall -Wextra -Werror -O3

NAME = push_swap

SRC = main.c \
	lst.c \
	operations.c \
	operations2.c \
	algo_optiop.c \
	algo_select.c \
	algo_select_extrema.c \
	algo_select_extrema2.c \
	extra.c

OBJ = $(SRC:.c=.o)

COMMIT = fast_push

all: $(NAME)

$(NAME): $(OBJ)
	@make -k -C libft
	@gcc $(FLAG) -o $(NAME) $(OBJ) -Llibft -lft
	@echo "$(NAME) built"

%.o: %.c
	@gcc $(FLAG) -c $< -o $@

clean:
	@make clean -k -C libft
	@rm -f $(OBJ)
	@echo "$(NAME) .o deleted"

fclean: clean
	@make fclean -k -C libft
	@rm -f $(NAME)
	@echo "$(NAME) deleted"

re: fclean all

pclean:
	@rm -f $(OBJ)
	@echo "$(NAME) .o deleted"
	@rm -f $(NAME)
	@echo "$(NAME) deleted"

renl: pclean all

push: fclean
	@git add --all
	@git commit -m $(COMMIT)
	@git push

.PHONY: all, clean, fclean, re
