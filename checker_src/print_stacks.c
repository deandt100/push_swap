/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 14:44:52 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/07/01 14:49:30 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	g_col(int i, char stack, t_info *info)
{
	if ((info->last_move == SA || info->last_move == SS) && (i == 0 || i == 1)
		&& stack == 'A')
		ft_putstr("\x1b[32m");
	if ((info->last_move == SB || info->last_move == SS) && (i == 0 || i == 1)
		&& stack == 'B')
		ft_putstr("\x1b[32m");
	if (info->last_move == RRR || info->last_move == RR)
		ft_putstr("\x1b[32m");
	if ((info->last_move == RRA || info->last_move == RA) && stack == 'A')
		ft_putstr("\x1b[32m");
	if ((info->last_move == RRB || info->last_move == RB) && stack == 'B')
		ft_putstr("\x1b[32m");
	if ((info->last_move == PB) && stack == 'B' && i == 0)
		ft_putstr("\x1b[32m");
	if ((info->last_move == PA) && stack == 'A' && i == 0)
		ft_putstr("\x1b[32m");
}

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
			g_col(i, 'A', info);
			ft_printf(" %d\x1b[0m", *(int*)trav_a->data);
			trav_a = trav_a->next;
		}
		ft_putchar('\t');
		if (trav_b != NULL)
		{
			g_col(i, 'B', info);
			ft_printf(" %d\x1b[0m", *(int*)trav_b->data);
			trav_b = trav_b->next;
		}
		ft_putchar('\n');
	}
	ft_printf("___\t___\n\x1b[33m A \t B\n\x1b[0m");
}
