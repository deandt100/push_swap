/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 08:56:50 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/30 16:49:21 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_src/checker.h"

void	check_dup(t_list *list)
{
	t_list	*trav;
	t_list	*cur;

	cur = list;
	while (cur)
	{
		trav = cur->next;
		while (trav)
		{
			if (*(int*)trav->data == *(int*)cur->data)
				error_print();
			trav = trav->next;
		}
		cur = cur->next;
	}
}
