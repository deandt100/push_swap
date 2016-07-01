/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 14:44:52 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/07/01 08:09:19 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		collapse_ops2(t_list *trav)
{
	if ((ft_strcmp("pa", (char*)trav->data) == 0) &&
		(ft_strcmp("rra", (char*)trav->next->data) == 0) &&
		(ft_strcmp("pb", (char*)trav->next->next->data) == 0))
	{
		return (1);
	}
	if ((ft_strcmp("pa", (char*)trav->data) == 0) &&
		(ft_strcmp("ra", (char*)trav->next->data) == 0) &&
		(ft_strcmp("pb", (char*)trav->next->next->data) == 0))
	{
		return (1);
	}
	return (0);
}

int		collapse_ops(t_list *trav)
{
	if ((ft_strcmp("sa", (char*)trav->data) == 0 &&
		ft_strcmp("sb", (char*)trav->next->data) == 0) ||
		(ft_strcmp("sb", (char*)trav->data) == 0 &&
		ft_strcmp("sa", (char*)trav->next->data) == 0))
	{
		return (1);
	}
	if ((ft_strcmp("ra", (char*)trav->data) == 0 &&
		ft_strcmp("rb", (char*)trav->next->data) == 0) ||
		(ft_strcmp("rb", (char*)trav->data) == 0 &&
		ft_strcmp("ra", (char*)trav->next->data) == 0))
	{
		return (1);
	}
	if ((ft_strcmp("rra", (char*)trav->data) == 0 &&
		ft_strcmp("rrb", (char*)trav->next->data) == 0) ||
		(ft_strcmp("rrb", (char*)trav->data) == 0 &&
		ft_strcmp("rra", (char*)trav->next->data) == 0))
	{
		return (1);
	}
	return (0);
}

void	compress_ops(t_list *ops, int *op_count)
{
	t_list	*trav;
	int		comp;

	trav = ops;
	comp = 0;
	while (trav != NULL)
	{
		if (trav->next && (comp = collapse_ops(trav)))
		{
			*op_count = *op_count - comp;
			trav = trav->next;
		}
		else if (trav->next && trav->next->next)
		{
			if ((comp = collapse_ops2(trav)))
			{
				*op_count = *op_count - comp;
				trav = trav->next->next;
			}
		}
		if (trav)
			trav = trav->next;
	}
}
