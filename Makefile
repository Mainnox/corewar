# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lyhamrou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/27 01:24:04 by lyhamrou          #+#    #+#              #
#    Updated: 2019/12/03 06:01:12 by akremer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_ASM = asm
NAME_COR = corewar

COMPILE = $(CC) -Wall -Wextra -Werror
LD_LIBS = -lft -L libft/
INCLUDES = -I includes/ -I libft/includes/
HEADER = includes/*.h

SRC_ASM_PATH = srcs/asm/
SRC_COR_PATH = srcs/corewar/
SRC_ASM_NAME = main.c error.c parsing.c test.c print.c open.c parsing_instruc.c \
			   check_parsing.c op.c change_label.c fill.c
SRC_COR_NAME = main.c init.c parsing.c
SRC_ASM = $(addprefix $(SRC_ASM_PATH),$(SRC_ASM_NAME))
SRC_COR = $(addprefix $(SRC_COR_PATH),$(SRC_COR_NAME))

OBJ_PATH = .obj/
OBJ_ASM_PATH = .obj/asm/
OBJ_COR_PATH = .obj/corewar/
OBJ_ASM_NAME = $(SRC_ASM_NAME:.c=.o)
OBJ_COR_NAME = $(SRC_COR_NAME:.c=.o)
OBJ_ASM = $(addprefix $(OBJ_ASM_PATH),$(OBJ_ASM_NAME))
OBJ_COR = $(addprefix $(OBJ_COR_PATH),$(OBJ_COR_NAME))

all: $(NAME_ASM) $(NAME_COR)

$(NAME_ASM): makedir libft $(OBJ_ASM)
	$(COMPILE) -o $(NAME_ASM) $(LD_LIBS) $(INCLUDES) $(OBJ_ASM)

$(NAME_COR): makedir libft $(OBJ_COR)
	$(COMPILE) -o $(NAME_COR) $(LD_LIBS) $(INCLUDES) $(OBJ_COR)

makedir:
	mkdir -p $(OBJ_PATH)
	mkdir -p $(OBJ_ASM_PATH)
	mkdir -p $(OBJ_COR_PATH)

libft:
	make -C libft/

$(OBJ_ASM_PATH)%.o: $(SRC_ASM_PATH)%.c $(HEADER)
	$(COMPILE) $(INCLUDES) -o $@ -c $<

$(OBJ_COR_PATH)%.o: $(SRC_COR_PATH)%.c $(HEADER)
	$(COMPILE) $(INCLUDES) -o $@ -c $<

clean:
	$(RM) -rf $(OBJ_PATH)
	make clean -C libft/

fclean: clean
	$(RM) -rf $(NAME_ASM)
	$(RM) -rf $(NAME_COR)
	make fclean -C libft/

re: fclean all

save: fclean
	git add .
	git commit -m "auto-save"
	git push

.PHONY: libft all clean fclean re
