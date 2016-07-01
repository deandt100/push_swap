/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   roll_back_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 15:25:31 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/30 16:46:02 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_inverse(t_info *info, int i)
{
	if (i <= 3)
		do_best(info, i, 0);
	else if (i == 4)
		do_best(info, 7, 0);
	else if (i == 5)
		do_best(info, 8, 0);
	else if (i == 6)
		do_best(info, 9, 0);
	else if (i == 7)
		do_best(info, 4, 0);
	else if (i == 8)
		do_best(info, 5, 0);
	else if (i == 9)
		do_best(info, 6, 0);
	else if (i == 10)
		do_best(info, 11, 0);
	else if (i == 11)
		do_best(info, 10, 0);
}

void	roll_back_moves(t_info *info, t_list *move_buffer)
{
	t_list	*trav;
	int		i;

	i = info->max;
	trav = move_buffer;
	while (trav)
	{
		do_inverse(info, *(int*)trav->data);
		trav = trav->next;
	}
	ft_lstdel(move_buffer);
}
