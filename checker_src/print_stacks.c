/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 14:44:52 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/30 16:54:49 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
