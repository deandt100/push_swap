/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 11:28:54 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/28 14:44:43 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_values(int i, int first_move, int *b_index, t_list *m_buffer)
{
	if (i == 0)
	{
		*b_index = first_move;
		m_buffer = ft_lstnew(b_index);
	}
}

static void	modify_values(int i, t_list *m_buffer, int *b_index, t_info *temp)
{
	if (i != 0)
	{
		*b_index = get_best(temp);
		ft_lstpush(&m_buffer, ft_lstnew(b_index));
	}
}

int			try_next(t_info *info, int moves, int first_move, int *moves_done)
{
	t_list	*move_buffer;
	int		i;
	int		*b_index;
	int		s_diff;
	t_info	temp;

	i = 0;
	info_mask(info, &temp);
	move_buffer = NULL;
	while (i < moves && i < info->max && calc_total_sortdiff(&temp) != 0)
	{
		do_tests(&temp);
		if ((b_index = (int*)malloc(sizeof(int))) != NULL)
		{
			init_values(i, first_move, b_index, move_buffer);
			modify_values(i, move_buffer, b_index, &temp);
			do_best(&temp, *b_index, 0);
		}
		i++;
	}
	*moves_done = i;
	s_diff = calc_total_sortdiff(&temp);
	roll_back_moves(&temp, move_buffer);
	delete_mask(&temp);
	return (s_diff);
}
