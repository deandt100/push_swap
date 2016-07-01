/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dumb_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 10:25:42 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/28 09:04:31 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	dumb_sort(t_algo *algo, t_info *info)
{
	int	small;
	int	pos;

	info->old_diff = 42;
	small = smallest(algo->stack_a, &pos);
	while (algo->elem_a != 0 && stack_sorted(algo->stack_a) == 0)
	{
		if (*(int*)algo->stack_a->data > *(int*)algo->stack_a->next->data)
			sa(algo);
		while (*(int*)algo->stack_a->data != smallest(algo->stack_a, &pos))
		{
			if (algo->elem_b / 2 - pos >= 0)
				ra(algo);
			else
				rra(algo);
		}
		if (stack_sorted(algo->stack_a) == 0)
			pb(algo);
	}
	while (algo->stack_b && algo->elem_b)
		pa(algo);
	return (algo->op_count);
}
