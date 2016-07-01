/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weight_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 11:28:54 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/30 12:56:27 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_tests(t_info *info)
{
	test_sa(info);
	test_sb(info);
	test_ss(info);
	test_ra(info);
	test_rb(info);
	test_rr(info);
	test_rra(info);
	test_rrb(info);
	test_rrr(info);
	test_pa(info);
	test_pb(info);
}

void	modify_diff(t_info *mask)
{
	if (*(int *)mask->a->data <= mask->median)
		mask->diffs->pb = -1000;
	if (mask->a && mask->a->next
		&& *(int *)mask->a->data <= mask->median
		&& *(int *)mask->a->next->data <= mask->median
		&& ft_strcmp(mask->diffs->last_a, "sa") != 0
		&& *(int *)mask->a->data > *(int *)mask->a->next->data)
		mask->diffs->sa = -2000;
	if (mask->a && mask->a->next
		&& ft_strcmp(mask->diffs->last_a, "sa") != 0
		&& *(int *)mask->a->data > *(int *)mask->a->next->data)
		mask->diffs->sa = -2000;
	if (stack_sorted(mask->a) == 1
		&& stack_sorted_desc(mask->b) == 1
		&& (ft_strcmp(mask->diffs->last_a, "pb") != 0))
		mask->diffs->pa = -2000;
	if (look_below_median(mask) == 1 && stack_sorted_desc(mask->b) == 1)
	{
		mask->diffs->ra -= 510;
		mask->diffs->rra -= 500;
	}
}

t_info	*weight_sort(t_info *info)
{
	t_info	*mask;

	mask = (t_info*)malloc(sizeof(t_info));
	info_mask(info, mask);
	ft_strcpy(mask->diffs->last_a, "qq");
	ft_strcpy(mask->diffs->last_b, "qq");
	mask->choice_diff = calc_total_sortdiff(mask);
	while (calc_total_sortdiff(mask) != 0 && mask->elem_steps < info->in_count)
	{
		if (mask->elem_a == mask->max && stack_sorted(mask->a) == 1)
			break ;
		do_tests(mask);
		modify_diff(mask);
		if (stack_sorted_desc(mask->b) == 1)
		{
			mask->diffs->sb = 200000;
			mask->diffs->ss = 200000;
			mask->diffs->rb = 200000;
			mask->diffs->rrb = 200000;
			mask->diffs->rrr = 200000;
		}
		do_best(mask, get_best(mask), 1);
	}
	return (mask);
}
