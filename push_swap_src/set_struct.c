/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 07:21:48 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/30 15:45:09 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_info(t_info *info)
{
	info->elem_a = 0;
	info->elem_b = 0;
	info->elem_steps = 0;
	info->b = NULL;
	info->a = NULL;
	info->diffs = (t_diff*)malloc(sizeof(t_diff));
	info->steps = NULL;
}

void	info_mask(t_info *src, t_info *mask)
{
	t_diff	*ret;

	*mask = *src;
	ret = (t_diff*)malloc(sizeof(t_diff));
	ret->sa = src->diffs->sa;
	ret->sb = src->diffs->sb;
	ret->ss = src->diffs->ss;
	ret->ra = src->diffs->ra;
	ret->rb = src->diffs->rb;
	ret->rr = src->diffs->rr;
	ret->rra = src->diffs->rra;
	ret->rrb = src->diffs->rrb;
	ret->rrr = src->diffs->rrr;
	ret->pa = src->diffs->pa;
	ret->pb = src->diffs->pb;
	mask->diffs = ret;
	mask->a = ft_lstcpy(src->a);
	mask->b = ft_lstcpy(src->b);
	mask->steps = NULL;
}

void	delete_mask(t_info *info)
{
	if (info)
	{
		if (info->diffs)
			free(info->diffs);
		if (info->a)
			ft_lstdel(info->a);
		if (info->b)
			ft_lstdel(info->b);
		if (info->steps)
			ft_lstdel(info->steps);
	}
}

t_algo	*new_algo(t_info *info)
{
	t_algo *new;

	new = (t_algo*)malloc(sizeof(t_algo));
	new->stack_a = ft_lstcpy(info->a);
	new->stack_b = ft_lstcpy(info->b);
	new->elem_a = info->elem_a;
	new->elem_b = info->elem_b;
	new->op_count = 0;
	new->operations = NULL;
	new->max = info->max;
	return (new);
}

void	delete_algo(t_algo **src)
{
	t_algo	*algo;

	algo = *src;
	if (algo->stack_a)
		ft_lstdel(algo->stack_a);
	if (algo->stack_b)
		ft_lstdel(algo->stack_b);
	if (algo->operations)
		ft_lstdel(algo->operations);
	free(*src);
	*src = NULL;
}
