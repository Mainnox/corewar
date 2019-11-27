# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akremer <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/19 14:26:56 by akremer           #+#    #+#              #
#    Updated: 2019/11/27 03:47:35 by akremer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = asm

LIB = libft/libftprintf.a

SRC =		srcs_asm/main.c						\
			srcs_asm/error.c					\
			srcs_asm/parsing.c					\
			srcs_asm/test.c

OBJ = $(SRC:%.c=%.o)

FLAGS = -Wall -Werror -Wextra

INCLUDE = -I include -I libft/includes/

all: $(NAME)


$(NAME): lib $(OBJ) 
	gcc $(FLAGS) $(INCLUDE) $(OBJ) $(LIB) -o $(NAME)

clean: 
	@rm -rf $(OBJ) && make -C ./libft/ clean

fclean: clean
	@rm -rf $(NAME)  && make -C ./libft/ fclean

re: fclean all

lib:
	@make -C ./libft/

save: fclean
	@rm -rf test
	@git add *
	@git commit -m "Sauvegarde auto !"
	@git push

