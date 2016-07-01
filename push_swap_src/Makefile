# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daviwel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/20 09:38:38 by daviwel           #+#    #+#              #
#    Updated: 2016/06/30 16:18:32 by ddu-toit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = main.c output.c calc.c calc2.c operations.c\
	  operations2.c operations3.c set_struct.c bubble_sort.c dumb_sort.c\
	  split_sort.c rollback_sort.c get_optimal.c get_best.c do_best_op.c\
	  try_next.c roll_back_moves.c weight_sort.c test_moves.c test_moves2.c\
	  test_moves3.c do_best_op2.c  compress_ops.c\
	  ../utils/check_stack.c ../utils/store_stack.c ../utils/error_check.c\
	  ../utils/check_dup.c ../utils/inc_elems.c ../utils/check_args.c

OBJ = main.o store_stack.o error_check.o check_dup.o inc_elems.o output.o\
	  check_stack.o calc.o calc2.o operations.o operations2.o operations3.o\
	  set_struct.o bubble_sort.o dumb_sort.o split_sort.o rollback_sort.o\
	  get_optimal.o get_best.o do_best_op.o try_next.o roll_back_moves.o\
	  weight_sort.o test_moves.o test_moves2.o test_moves3.o do_best_op2.o\
	  check_args.o compress_ops.o

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

norme:
	norminette $(SRC) checker.h

