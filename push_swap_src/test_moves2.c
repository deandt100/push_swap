/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_moves2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 07:55:08 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/30 16:46:27 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test_rb(t_info *info)
{
	if ((info->b && ft_strcmp(info->diffs->last_b, "rrb") != 0)
		&& info->elem_b > 1)
	{
		ft_lstrot(&info->b, info->elem_b);
		info->diffs->rb = calc_total_sortdiff(info);
		info->diffs->rb -= info->elem_b;
		ft_lstrotrev(&info->b, info->elem_b);
	}
	else
		info->diffs->rb = 2147483647;
}

void	test_rrb(t_info *info)
{
	if ((info->b && ft_strcmp(info->diffs->last_b, "rb") != 0)
		&& info->elem_b > 1)
	{
		ft_lstrotrev(&info->b, info->elem_b);
		info->diffs->rrb = calc_total_sortdiff(info);
		info->diffs->rrb -= info->elem_b;
		ft_lstrot(&info->b, info->elem_b);
	}
	else
		info->diffs->rrb = 2147483647;
}

void	test_rrr(t_info *info)
{
	if ((info->a && info->b && ft_strcmp(info->diffs->last_a, "rrr") != 0)
		&& (ft_strncmp(info->diffs->last_b, "r", 1) != 0)
		&& (ft_strncmp(info->diffs->last_a, "r", 1) != 0))
	{
		ft_lstrotrev(&info->b, info->elem_b);
		ft_lstrotrev(&info->a, info->elem_a);
		info->diffs->rrr = calc_total_sortdiff(info);
		ft_lstrot(&info->b, info->elem_b);
		ft_lstrot(&info->a, info->elem_a);
	}
	else
		info->diffs->rrr = 2147483647;
}

void	test_rr(t_info *info)
{
	if ((info->a && info->b && ft_strcmp(info->diffs->last_a, "rr") != 0)
		&& (ft_strcmp(info->diffs->last_b, "r") != 0)
		&& (ft_strncmp(info->diffs->last_a, "r", 1) != 0))
	{
		ft_lstrot(&info->b, info->elem_b);
		ft_lstrot(&info->a, info->elem_a);
		info->diffs->rr = calc_total_sortdiff(info);
		ft_lstrotrev(&info->b, info->elem_b);
		ft_lstrotrev(&info->a, info->elem_a);
	}
	else
		info->diffs->rr = 2147483647;
}
