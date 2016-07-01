/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_moves3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 08:10:24 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/30 16:46:39 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test_pa(t_info *info)
{
	if (info->b && ft_strcmp(info->diffs->last_a, "pb") != 0)
	{
		ft_lstpushpop(&info->b, &info->a);
		info->diffs->pa = calc_total_sortdiff(info);
		ft_lstpushpop(&info->a, &info->b);
	}
	else
		info->diffs->pa = 2147483647;
}

void	test_pb(t_info *info)
{
	if (info->a && ft_strcmp(info->diffs->last_b, "pa") != 0)
	{
		ft_lstpushpop(&info->a, &info->b);
		info->diffs->pb = calc_total_sortdiff(info);
		ft_lstpushpop(&info->b, &info->a);
	}
	else
		info->diffs->pb = 2147483647;
}
