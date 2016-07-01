# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daviwel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/20 09:38:38 by daviwel           #+#    #+#              #
#    Updated: 2016/06/30 17:02:41 by ddu-toit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

SRC = main.c read_instructions.c validate.c ../utils/store_stack.c\
	  ../utils/error_check.c ../utils/inc_elems.c ../utils/check_args.c\
	  ../utils/check_stack.c ../utils/check_dup.c print_stacks.c

OBJ = main.o read_instructions.o validate.o store_stack.o error_check.o \
	  inc_elems.o check_args.o print_stacks.o check_stack.o check_dup.o

CFLAG = -Wall -Werror -Wextra

ATTACH = -L ../libft/ -lft

all: $(NAME)

$(NAME):
	clang $(CFLAG) -I ../lbft -c $(SRC)
	clang $(CFLAG) -o $(NAME) $(OBJ) $(ATTACH)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

run:
	./printer | ./checker 4 3 2 1

norme:
	norminette $(SRC) checker.h

