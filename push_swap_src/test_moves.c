/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 07:37:27 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/28 09:46:03 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test_sa(t_info *info)
{
	if ((info->a && ft_strcmp(info->diffs->last_a, "sa") != 0)
		&& info->elem_a > 1)
	{
		ft_lstswap(info->a);
		info->diffs->sa = calc_total_sortdiff(info);
		ft_lstswap(info->a);
	}
	else
		info->diffs->sa = 2147483647;
}

void	test_sb(t_info *info)
{
	if (info->b && ft_strcmp(info->diffs->last_b, "sb") != 0
		&& stack_sorted_desc(info->b) == 0 && info->elem_b > 1)
	{
		ft_lstswap(info->b);
		info->diffs->sb = calc_total_sortdiff(info);
		ft_lstswap(info->b);
	}
	else
		info->diffs->sb = 2147483647;
}

void	test_ss(t_info *info)
{
	if ((info->a && info->b && ft_strncmp(info->diffs->last_a, "s", 1) != 0)
		&& (ft_strncmp(info->diffs->last_b, "s", 1) != 0))
	{
		ft_lstswap(info->b);
		ft_lstswap(info->a);
		info->diffs->ss = calc_total_sortdiff(info);
		ft_lstswap(info->b);
		ft_lstswap(info->a);
	}
	else
		info->diffs->ss = 2147483647;
}

void	test_ra(t_info *info)
{
	if ((info->a && ft_strcmp(info->diffs->last_a, "rra") != 0)
		&& info->elem_a > 1)
	{
		ft_lstrot(&info->a, info->elem_a);
		info->diffs->ra = calc_total_sortdiff(info);
		info->diffs->ra -= info->elem_a;
		ft_lstrotrev(&info->a, info->elem_a);
	}
	else
		info->diffs->ra = 2147483647;
}

void	test_rra(t_info *info)
{
	if ((info->a && ft_strcmp(info->diffs->last_a, "ra") != 0)
		&& info->elem_a > 1)
	{
		ft_lstrotrev(&info->a, info->elem_a);
		info->diffs->rra = calc_total_sortdiff(info);
		info->diffs->rra -= info->elem_a;
		ft_lstrot(&info->a, info->elem_a);
	}
	else
		info->diffs->rra = 2147483647;
}
