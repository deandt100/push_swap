/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 08:47:25 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/07/01 08:00:06 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_algo *algo)
{
	if (algo->stack_a != NULL && algo->stack_a->next != NULL)
	{
		ft_lstswap(algo->stack_a);
		ft_lstappend(&algo->operations, ft_lstnew(ft_strdup("sa")));
		algo->op_count++;
	}
	else
		ft_putendl_fd("Error : Not enough elements to swap stack a", 2);
}

void	sb(t_algo *algo)
{
	if (algo->stack_b != NULL && algo->stack_b->next != NULL)
	{
		ft_lstswap(algo->stack_b);
		ft_lstappend(&algo->operations, ft_lstnew(ft_strdup("sb")));
		algo->op_count++;
	}
	else
		ft_putendl_fd("Error : Not enough elements to swap stack b", 2);
}

void	ss(t_algo *algo)
{
	if (algo->stack_a != NULL && algo->stack_a->next != NULL
		&& algo->stack_b != NULL && algo->stack_b->next != NULL)
	{
		ft_lstswap(algo->stack_b);
		ft_lstswap(algo->stack_a);
		ft_lstappend(&algo->operations, ft_lstnew(ft_strdup("ss")));
		algo->op_count++;
	}
	else
		ft_putendl_fd("Error : Not enough elements to swap stacks", 2);
}

void	ra(t_algo *algo)
{
	if (algo->stack_a != NULL && algo->stack_a->next != NULL)
	{
		ft_lstrot(&algo->stack_a, algo->elem_a);
		ft_lstappend(&algo->operations, ft_lstnew(ft_strdup("ra")));
		algo->op_count++;
	}
	else
		ft_putendl_fd("Error : Not enough elements to rotate stack a", 2);
}

void	rb(t_algo *algo)
{
	if (algo->stack_b != NULL && algo->stack_b->next != NULL)
	{
		ft_lstrot(&algo->stack_b, algo->elem_b);
		ft_lstappend(&algo->operations, ft_lstnew(ft_strdup("rb")));
		algo->op_count++;
	}
	else
		ft_putendl_fd("Error : Not enough elements to rotate stack b", 2);
}
