/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 09:09:19 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/30 16:47:07 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_curpos(t_list *list, t_list *node)
{
	int		i;
	t_list	*trav;

	i = 0;
	trav = list;
	while (trav != NULL)
	{
		if (trav == node)
			return (i);
		i++;
		trav = trav->next;
	}
	return (-1);
}

int		short_path(int up, int down)
{
	if (up <= down)
		return (up);
	else
		return (down);
}

void	init(int cur, int *up, int *down, int *pos)
{
	*pos = cur;
	*down = 0;
	*up = 0;
}

int		calc_moves_to_op(int opt, int cur, t_info *info)
{
	int		pos;
	int		up;
	int		down;

	init(cur, &up, &down, &pos);
	while (pos != opt)
		if (pos == info->max)
			pos = 0;
		else
		{
			pos++;
			up++;
		}
	pos = cur;
	while (pos != opt)
		if (pos == 0)
			pos = info->max;
		else
		{
			pos--;
			down++;
		}
	return (short_path(up, down));
}

int		calc_total_sortdiff(t_info *info)
{
	int		s_diff;
	t_list	*trav;
	int		c_pos;

	s_diff = 0;
	trav = info->a;
	while (trav)
	{
		c_pos = get_curpos(info->a, trav);
		s_diff += calc_moves_to_op(trav->op_pos, c_pos, info);
		trav = trav->next;
	}
	trav = info->b;
	while (trav)
	{
		s_diff += calc_moves_to_op(0, get_curpos(info->b, trav), info) + 1;
		s_diff += calc_moves_to_op(trav->op_pos, 0, info);
		trav = trav->next;
	}
	return (s_diff);
}
