/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 14:44:52 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/30 15:39:28 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_list *stack_a, t_list *stack_b, t_info *info)
{
	int		i;
	t_list	*trav_a;
	t_list	*trav_b;

	i = -1;
	trav_a = stack_a;
	trav_b = stack_b;
	while (++i < info->max)
	{
		if (trav_a != NULL)
		{
			ft_putchar(' ');
			ft_putnbr(*(int*)trav_a->data);
			trav_a = trav_a->next;
		}
		ft_putchar('\t');
		if (trav_b != NULL)
		{
			ft_putchar(' ');
			ft_putnbr(*(int*)trav_b->data);
			trav_b = trav_b->next;
		}
		ft_putchar('\n');
	}
	ft_printf("___\t___\n a \t b\n");
}

int		collapse_step2(t_list *trav)
{
	if ((ft_strcmp("pa", (char*)trav->data) == 0) &&
		(ft_strcmp("rra", (char*)trav->next->data) == 0) &&
		(ft_strcmp("pb", (char*)trav->next->next->data) == 0))
	{
		ft_putendl("rra\nsa");
		return (1);
	}
	if ((ft_strcmp("pa", (char*)trav->data) == 0) &&
		(ft_strcmp("ra", (char*)trav->next->data) == 0) &&
		(ft_strcmp("pb", (char*)trav->next->next->data) == 0))
	{
		ft_putendl("sa\nra");
		return (1);
	}
	return (0);
}

int		collapse_step(t_list *trav)
{
	if ((ft_strcmp("sa", (char*)trav->data) == 0 &&
		ft_strcmp("sb", (char*)trav->next->data) == 0) ||
		(ft_strcmp("sb", (char*)trav->data) == 0 &&
		ft_strcmp("sa", (char*)trav->next->data) == 0))
	{
		ft_putendl("ss");
		return (1);
	}
	if ((ft_strcmp("ra", (char*)trav->data) == 0 &&
		ft_strcmp("rb", (char*)trav->next->data) == 0) ||
		(ft_strcmp("rb", (char*)trav->data) == 0 &&
		ft_strcmp("ra", (char*)trav->next->data) == 0))
	{
		ft_putendl("rr");
		return (1);
	}
	if ((ft_strcmp("rra", (char*)trav->data) == 0 &&
		ft_strcmp("rrb", (char*)trav->next->data) == 0) ||
		(ft_strcmp("rrb", (char*)trav->data) == 0 &&
		ft_strcmp("rra", (char*)trav->next->data) == 0))
	{
		ft_putendl("rrr");
		return (1);
	}
	return (0);
}

void	print_steps(t_list *steps)
{
	t_list	*trav;

	trav = steps;
	while (trav != NULL)
	{
		if (trav->next && collapse_step(trav))
			trav = trav->next;
		else if (trav->next && trav->next->next && collapse_step2(trav))
			trav = trav->next->next;
		else
			ft_printf("%s\n", (char*)trav->data);
		if (trav)
			trav = trav->next;
	}
}
