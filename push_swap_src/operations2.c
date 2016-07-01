/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 08:54:34 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/30 13:50:31 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_algo *algo)
{
	if (algo->stack_a != NULL && algo->stack_a->next != NULL
		&& algo->stack_b != NULL && algo->stack_b->next != NULL)
	{
		ft_lstrot(&algo->stack_a, algo->elem_a);
		ft_lstrot(&algo->stack_b, algo->elem_b);
		ft_lstappend(&algo->operations, ft_lstnew(ft_strdup("rr")));
		algo->op_count++;
	}
	else
		ft_putendl_fd("Error : Not enough elements to rotate stacks", 2);
}

void	rra(t_algo *algo)
{
	if (algo->stack_a != NULL && algo->stack_a->next != NULL)
	{
		ft_lstrotrev(&algo->stack_a, algo->elem_a);
		ft_lstappend(&algo->operations, ft_lstnew(ft_strdup("rra")));
		algo->op_count++;
	}
	else
		ft_putendl_fd("Error : Not enough elements to rev-rotate stack a", 2);
}

void	rrb(t_algo *algo)
{
	if (algo->stack_b != NULL && algo->stack_b->next != NULL)
	{
		ft_lstrotrev(&algo->stack_b, algo->elem_b);
		ft_lstappend(&algo->operations, ft_lstnew(ft_strdup("rrb")));
		algo->op_count++;
	}
	else
		ft_putendl_fd("Error : Not enough elements to rev-rotate stack b", 2);
}

void	rrr(t_algo *algo)
{
	if (algo->stack_a != NULL && algo->stack_a->next != NULL
		&& algo->stack_b != NULL && algo->stack_b->next != NULL)
	{
		ft_lstrotrev(&algo->stack_a, algo->elem_a);
		ft_lstrotrev(&algo->stack_b, algo->elem_b);
		ft_lstappend(&algo->operations, ft_lstnew(ft_strdup("rrr")));
		algo->op_count++;
	}
	else
		ft_putendl_fd("Error : Not enough elements to rev-rotate stacks", 2);
}
