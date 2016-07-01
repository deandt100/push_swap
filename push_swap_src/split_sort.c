/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 11:37:40 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/30 15:58:45 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*get_last(t_list *list)
{
	t_list *ret;

	ret = list;
	if (ret)
	{
		while (ret->next != NULL)
			ret = ret->next;
	}
	return (ret);
}

void	fill_a(t_algo *algo, t_info *info)
{
	t_list	*last_a;

	last_a = get_last(algo->stack_a);
	while (algo->stack_b && (algo->op_count < info->in_count))
	{
		if ((algo->stack_b->next
			&& *(int*)algo->stack_b->data < *(int*)algo->stack_b->next->data)
			&& (algo->stack_a->next
			&& *(int*)algo->stack_a->data > *(int*)algo->stack_a->next->data))
			ss(algo);
		if (algo->stack_b->next
			&& *(int*)algo->stack_b->data < *(int*)algo->stack_b->next->data)
			sb(algo);
		if (algo->stack_a->next
			&& *(int*)algo->stack_a->data > *(int*)algo->stack_a->next->data)
			sa(algo);
		pa(algo);
		last_a = get_last(algo->stack_a);
	}
}

void	pre_pb_ops(t_algo *algo, t_info *info)
{
	if (algo->stack_a && *(int*)algo->stack_a->data > info->median
		&& algo->elem_a > 1)
		ra(algo);
	if (algo->stack_b && *(int*)algo->stack_b->data < info->median
		&& algo->elem_b > 1)
		rb(algo);
	if (algo->stack_a && algo->stack_a->next
		&& *(int*)algo->stack_a->data > *(int*)algo->stack_a->next->data)
		sa(algo);
	if (algo->stack_b && algo->stack_b->next
		&& *(int*)algo->stack_b->data < *(int*)algo->stack_b->next->data)
		sb(algo);
}

void	split_sort(t_algo *algo, t_info *info)
{
	int		wave_a;
	int		wave_b;
	int		i;

	wave_b = 0;
	while ((stack_sorted(algo->stack_a) == 0 || algo->elem_a < algo->max)
		&& (algo->op_count < info->in_count))
	{
		wave_a = c_wave(algo->stack_a);
		i = -1;
		while (wave_a + 1 > wave_b && algo->stack_a && ++i <= info->max / 2)
		{
			pre_pb_ops(algo, info);
			if (stack_sorted(algo->stack_a))
				break ;
			else
				pb(algo);
			wave_a = c_wave(algo->stack_a);
			wave_b = c_wave_rev(algo->stack_b);
		}
		fill_a(algo, info);
		wave_a = c_wave(algo->stack_a);
		wave_b = c_wave_rev(algo->stack_b);
	}
}
