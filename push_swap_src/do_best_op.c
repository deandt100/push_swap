/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_best_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 08:20:27 by daviwel           #+#    #+#             */
/*   Updated: 2016/07/01 07:33:05 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_best5(t_info *info, int i, int save)
{
	if (i == RRR)
	{
		ft_lstrotrev(&info->a, info->elem_a);
		ft_lstrotrev(&info->b, info->elem_b);
		if (save)
			ft_lstappend(&info->steps, ft_lstnew(ft_strdup("rrr")));
		ft_strcpy(info->diffs->last_a, "rrr");
		ft_strcpy(info->diffs->last_b, "rrr");
	}
	else
		do_best6(info, i, save);
}

void	do_best4(t_info *info, int i, int save)
{
	info->elem_steps++;
	if (i == RRA)
	{
		ft_lstrotrev(&info->a, info->elem_a);
		if (save)
			ft_lstappend(&info->steps, ft_lstnew(ft_strdup("rra")));
		ft_strcpy(info->diffs->last_a, "rra");
		if (ft_strcmp(info->diffs->last_b, "pb") == 0)
			ft_strcpy(info->diffs->last_b, "qq");
	}
	else if (i == RRB)
	{
		ft_lstrotrev(&info->b, info->elem_b);
		if (save)
			ft_lstappend(&info->steps, ft_lstnew(ft_strdup("rrb")));
		ft_strcpy(info->diffs->last_b, "rrb");
		if (ft_strcmp(info->diffs->last_a, "pa") == 0)
			ft_strcpy(info->diffs->last_a, "qq");
	}
	else
		do_best5(info, i, save);
}

void	do_best3(t_info *info, int i, int save)
{
	if (i == RB)
	{
		ft_lstrot(&info->b, info->elem_b);
		if (save)
			ft_lstappend(&info->steps, ft_lstnew(ft_strdup("rb")));
		ft_strcpy(info->diffs->last_b, "rb");
		if (ft_strcmp(info->diffs->last_a, "pa") == 0)
			ft_strcpy(info->diffs->last_a, "qq");
	}
	else if (i == RR)
	{
		ft_lstrot(&info->a, info->elem_a);
		ft_lstrot(&info->b, info->elem_b);
		if (save)
			ft_lstappend(&info->steps, ft_lstnew(ft_strdup("rr")));
		ft_strcpy(info->diffs->last_a, "rr");
		ft_strcpy(info->diffs->last_b, "rr");
	}
	else
		do_best4(info, i, save);
}

void	do_best2(t_info *info, int i, int save)
{
	if (i == SS)
	{
		ft_lstswap(info->a);
		ft_lstswap(info->b);
		if (save)
			ft_lstappend(&info->steps, ft_lstnew(ft_strdup("ss")));
		ft_strcpy(info->diffs->last_a, "ss");
		ft_strcpy(info->diffs->last_b, "ss");
	}
	else if (i == RA)
	{
		ft_lstrot(&info->a, info->elem_a);
		if (save)
			ft_lstappend(&info->steps, ft_lstnew(ft_strdup("ra")));
		ft_strcpy(info->diffs->last_a, "ra");
		if (ft_strcmp(info->diffs->last_b, "pb") == 0)
			ft_strcpy(info->diffs->last_b, "qq");
	}
	else
		do_best3(info, i, save);
}

void	do_best(t_info *info, int i, int save)
{
	info->elem_steps++;
	if (i == SA)
	{
		ft_lstswap(info->a);
		if (save)
			ft_lstappend(&info->steps, ft_lstnew(ft_strdup("sa")));
		ft_strcpy(info->diffs->last_a, "sa");
		if (ft_strcmp(info->diffs->last_b, "pb") == 0)
			ft_strcpy(info->diffs->last_b, "qq");
	}
	else if (i == SB)
	{
		ft_lstswap(info->b);
		if (save)
			ft_lstappend(&info->steps, ft_lstnew(ft_strdup("sb")));
		ft_strcpy(info->diffs->last_b, "sb");
		if (ft_strcmp(info->diffs->last_a, "pa") == 0)
			ft_strcpy(info->diffs->last_a, "qq");
	}
	else
		do_best2(info, i, save);
}
