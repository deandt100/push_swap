/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 07:43:15 by daviwel           #+#    #+#             */
/*   Updated: 2016/07/01 16:01:37 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Runs sorting algorithms and stores results
*/

void	run_test2(t_algo *best, t_info *info)
{
	t_info	*w_sort;

	w_sort = weight_sort(info);
	compress_ops(w_sort->steps, &w_sort->elem_steps);
	rollback_sort(info);
	compress_ops(info->steps, &info->elem_steps);
	if ((info->elem_steps < best->op_count && stack_sorted(info->a)
		&& info->elem_a == info->max)
		|| (w_sort->elem_steps < best->op_count && stack_sorted(w_sort->a)
		&& w_sort->elem_a == info->max))
	{
		if (info->elem_steps < w_sort->elem_steps
			&& stack_sorted(info->a) && info->elem_a == info->max)
			print_steps(info->steps);
		else if (stack_sorted(w_sort->a) && w_sort->elem_a == info->max)
			print_steps(w_sort->steps);
		else
			print_steps(best->operations);
	}
	else
		print_steps(best->operations);
	delete_mask(w_sort);
	delete_mask(info);
}

void	delete(t_algo *b_sort, t_algo *s_sort, t_algo *d_sort)
{
	delete_algo(&b_sort);
	delete_algo(&s_sort);
	delete_algo(&d_sort);
}

void	run_sort_algorithms(t_info *info)
{
	t_algo	*best;
	t_algo	*b_sort;
	t_algo	*s_sort;
	t_algo	*d_sort;

	b_sort = new_algo(info);
	s_sort = new_algo(info);
	d_sort = new_algo(info);
	info->in_count = dumb_sort(d_sort, info);
	compress_ops(d_sort->operations, &info->in_count);
	best = d_sort;
	bubble_sort(b_sort, info);
	compress_ops(b_sort->operations, &b_sort->op_count);
	if (b_sort->op_count < best->op_count && stack_sorted(b_sort->stack_a)
		&& b_sort->elem_a == info->max)
		best = b_sort;
	split_sort(s_sort, info);
	compress_ops(s_sort->operations, &s_sort->op_count);
	if (s_sort->op_count < best->op_count && stack_sorted(s_sort->stack_a)
		&& s_sort->elem_a == info->max)
		best = s_sort;
	run_test2(best, info);
	delete(b_sort, s_sort, d_sort);
}

int		main(int argc, char **argv)
{
	t_info	info;
	int		n;

	init_info(&info);
	n = check_args(argc, argv);
	if (n)
		info.elem_a = store_stack(&info.a, n, ft_strsplit(argv[1], ' '), !(n));
	else
		info.elem_a = store_stack(&info.a, argc, argv, !(n));
	info.max = info.elem_a;
	check_dup(info.a);
	info.median = median(&info);
	run_sort_algorithms(&info);
	return (0);
}
