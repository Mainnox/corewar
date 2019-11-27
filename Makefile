# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lyhamrou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/27 01:24:04 by lyhamrou          #+#    #+#              #
#    Updated: 2019/11/27 03:52:26 by lyhamrou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_ASM = asm
NAME_COR = corewar

COMPILE = $(CC) -Wall -Wextra -Werror
LD_LIBS = -lft -L libft/
INCLUDES = -I includes/ -I libft/
HEADER = includes/*.h

SRC_ASM_PATH = srcs/asm/
SRC_COR_PATH = srcs/corewar/
SRC_ASM_NAME = main_asm.c
SRC_COR_NAME = main_cor.c
SRC_ASM = $(addprefix $(SRC_ASM_PATH),$(SRC_ASM_NAME))
SRC_COR = $(addprefix $(SRC_COR_PATH),$(SRC_COR_NAME))

OBJ_PATH = .obj/
OBJ_ASM_NAME = $(SRC_ASM_NAME:.c=.o)
OBJ_COR_NAME = $(SRC_COR_NAME:.c=.o)
OBJ_ASM = $(addprefix $(OBJ_PATH),$(OBJ_ASM_NAME))
OBJ_COR = $(addprefix $(OBJ_PATH),$(OBJ_COR_NAME))

all: $(NAME_ASM) $(NAME_COR)

$(NAME_ASM): libft $(OBJ_ASM)
	$(COMPILE) -o $(NAME_ASM) $(LD_LIBS) $(INCLUDES) $(OBJ_ASM)

$(NAME_COR): libft $(OBJ_COR)
	$(COMPILE) -o $(NAME_COR) $(LD_LIBS) $(INCLUDES) $(OBJ_COR)

libft:
	make -C libft/

$(OBJ_PATH)%.o: $(SRC_ASM_PATH)%.c $(HEADER)
	mkdir -p $(OBJ_PATH)
	$(COMPILE) $(INCLUDES) -o $@ -c $<

$(OBJ_PATH)%.o: $(SRC_COR_PATH)%.c $(HEADER)
	mkdir -p $(OBJ_PATH)
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
