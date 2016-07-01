/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 08:25:16 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/28 09:05:08 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(t_algo *algo, t_info *info)
{
	t_list	*cur;

	while ((stack_sorted(algo->stack_a) == 0 || algo->elem_a < algo->max)
			&& (algo->op_count < info->in_count))
	{
		cur = algo->stack_a;
		if (cur && cur->next && ((*(int*)cur->data > *(int*)cur->next->data)
			|| *(int*)cur->next->data))
			sa(algo);
		else
			ra(algo);
	}
}
