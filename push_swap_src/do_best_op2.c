/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_best_op2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 08:20:27 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/30 13:24:00 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_best6(t_info *info, int i, int save)
{
	if (i == PA)
	{
		ft_lstpushpop(&info->b, &info->a);
		inc_elems(info, 0);
		if (save)
			ft_lstappend(&info->steps, ft_lstnew(ft_strdup("pa")));
		ft_strcpy(info->diffs->last_a, "pa");
	}
	else if (i == PB)
	{
		ft_lstpushpop(&info->a, &info->b);
		inc_elems(info, 1);
		if (save)
			ft_lstappend(&info->steps, ft_lstnew(ft_strdup("pb")));
		ft_strcpy(info->diffs->last_b, "pb");
	}
}

void	set_to_max(int *num)
{
	*num = 2147483647;
}

void	do_function(t_diff *diff, int i, void (f)(int *))
{
	if (i == 1)
		f(&diff->sa);
	else if (i == 2)
		f(&diff->sb);
	else if (i == 3)
		f(&diff->ss);
	else if (i == 4)
		f(&diff->ra);
	else if (i == 5)
		f(&diff->rb);
	else if (i == 6)
		f(&diff->rr);
	else if (i == 7)
		f(&diff->rra);
	else if (i == 8)
		f(&diff->rrb);
	else if (i == 9)
		f(&diff->rrr);
	else if (i == 10)
		f(&diff->pa);
	else if (i == 11)
		f(&diff->pb);
}
