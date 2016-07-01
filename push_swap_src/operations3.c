/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 08:53:24 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/28 08:53:26 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_algo *algo)
{
	if (algo->stack_b != NULL)
	{
		ft_lstpushpop(&algo->stack_b, &algo->stack_a);
		ft_lstappend(&algo->operations, ft_lstnew(ft_strdup("pa")));
		algo->op_count++;
		algo->elem_a++;
		algo->elem_b--;
	}
	else
		ft_putendl_fd("Error : Nothing on stack b to pop.", 2);
}

void	pb(t_algo *algo)
{
	if (algo->stack_a != NULL)
	{
		ft_lstpushpop(&algo->stack_a, &algo->stack_b);
		ft_lstappend(&algo->operations, ft_lstnew(ft_strdup("pb")));
		algo->op_count++;
		algo->elem_a--;
		algo->elem_b++;
	}
	else
		ft_putendl_fd("Error : Nothing on stack a to pop.", 2);
}
