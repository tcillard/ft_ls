# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcillard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/27 05:29:43 by tcillard          #+#    #+#              #
#    Updated: 2019/05/13 22:10:20 by tcillard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRC_NAME = ft_record_name.c\
		   ft_indent.c \
		   ft_sort_lst2.c \
		   ft_path.c \
		   ft_sort_lst.c \
		   main.c \
		   ft_ls.c \
		   ft_parser.c \
		   ft_error.c \
		   ft_stock.c \
		   ft_sort_stock.c \
		   ft_print.c \
		   ft_color.c \
		   ft_spec_law.c \
		   ft_sort_path.c

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC_PATH = ./src
OBJ_PATH = ./obj

LIBFT = -L ./libft  -lft
INCLUDE = -I include/ -I ./libft

NAME = ft_ls

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@$(CC) -c $(INCLUDE) $< -o $@
	@echo "\033[0m$< -> $@ \033[38;2;0;255;0m[ok]\033[0m"

dir:
	@-mkdir $(OBJ_PATH)

$(NAME): libft dir $(OBJ) logo
	@$(CC) $(FLAGS) $(INCLUDE) $(SRC) $(LIBFT) -o $(NAME)

libft:
	@make -C libft/

logo:
		@echo "\033[38;2;255;255;255m8888888888 88888888888                    888      .d8888b.  "
		@echo "\033[38;2;255;220;220m888            888                        888     d88P  Y88b "
		@echo "\033[38;2;255;170;170m888            888                        888     Y88b.      "
		@echo "\033[38;2;255;150;150m8888888        888                        888      \"Y888b.   "
		@echo "\033[38;2;255;100;100m888            888                        888         \"Y88b. "
		@echo "\033[38;2;255;50;50m888            888                        888           \"888 "
		@echo "\033[38;2;255;25;25m888            888                        888     Y88b  d88P "
		@echo "\033[38;2;255;0;0m888            888          88888888      88888888 \"Y8888P\"  "

clean:
	@$(MAKE) -C libft clean
	@rm -rf ./obj

fclean: clean
	@$(MAKE) -C libft/ fclean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re logo libft
