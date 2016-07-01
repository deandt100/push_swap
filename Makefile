# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daviwel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/20 09:32:56 by daviwel           #+#    #+#              #
#    Updated: 2016/06/30 17:18:09 by ddu-toit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	make -C libft/
	make -C checker_src/
	make -C push_swap_src/
	cp push_swap_src/push_swap .
	cp checker_src/checker .

p:
	make re -C push_swap_src/
	cp push_swap_src/push_swap .

clean:
	make clean -C libft/
	make clean -C checker_src/
	make clean -C push_swap_src/

fclean:
	make fclean -C libft/
	make fclean -C checker_src/
	make fclean -C push_swap_src/
	/bin/rm -f push_swap
	/bin/rm -f checker

re: fclean all


