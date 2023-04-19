# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/06 20:59:26 by dacortes          #+#    #+#              #
#    Updated: 2023/04/19 10:39:28 by dacortes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# =============================== VARIABLES ================================== #

NAME = push_swap
CC = gcc
RM = rm -rf
LIBC = ar -rcs
FLAGS = -Wall -Wextra -Werror -g

# =========================== SOURCES ======================================== #

SRC = check/check_arg.c\
	destroy/destroy.c\
	init/init.c\
	instructions/push.c instructions/reverse_rotate.c instructions/swap.c\
	instructions/rotate.c\
	sorted/sorted.c sorted/size3.c sorted/size4.c sorted/size5.c\
	main.c\
	utils.c
LIBFT = ./libft/
L_SRC = ./src
L_LIB = ./libft/libft.a
INC			=	-I ./inc/\
				-I ./libft/\

# =========================== DIRECTORIES ==================================== #

D_OBJ = $(L_SRC)/obj
#.o
OBJ = $(addprefix $(D_OBJ)/, $(SRC:.c=.o))
DEP = $(addprefix $(D_OBJ)/, $(SRC:.c=.d))

# =========================== BOLD COLORS ==================================== #

E = \033[m
R = \033[31m
G = \033[32m
Y = \033[33m
B = \033[34m
#Font
ligth = \033[1m
dark = \033[2m
italic = \033[3m

# ========================== MAKE RULES ===================================== #
#Rules
all: dir $(NAME)
-include $(DEP)
dir:
	@make bonus -C $(LIBFT)
	@mkdir -p $(D_OBJ)
	@mkdir -p $(D_OBJ)/check
	@mkdir -p $(D_OBJ)/destroy
	@mkdir -p $(D_OBJ)/init
	@mkdir -p $(D_OBJ)/instructions
	@mkdir -p $(D_OBJ)/sorted
$(D_OBJ)/%.o:$(L_SRC)/%.c
	@printf "$(ligth)$(Y)\r$@...$(E)"
	@$(CC) -MMD $(FLAGS) -c $< -o $@ $(INC)
$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) $(L_LIB) -o $(NAME) $(INC)
	@echo  "\n$(B)$(ligth)-->$(G) ==== Project push swap compiled! ==== ✅$(E)"

# ========================== CLEAN   ===================================== #

.PHONY: clean fclean re
fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(LIBFT)
	@echo "$(B)$(ligth)-->$(E)$(ligth) ==== fractol object files cleaned! ==== ✅$(E)"
clean:
	@$(RM) $(D_OBJ)
	@make clean -C $(LIBFT)
	@echo "$(B)$(ligth)-->$(E)$(ligth) ==== fractol executable files and name cleaned! ==== ✅$(E)"
re: fclean all