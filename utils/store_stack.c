/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 07:52:30 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/30 16:50:18 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_src/checker.h"

int		store_stack(t_list **list, int argc, char **argv, int u_arg)
{
	int	*num;
	int	elem;

	elem = 0;
	if (argc > 1)
	{
		num = (int*)malloc(sizeof(int));
		*num = check_int(argv[--argc]);
		elem++;
		*list = ft_lstnew(num);
		while (argc >= 1 + u_arg)
		{
			num = (int*)malloc(sizeof(int));
			*num = check_int(argv[--argc]);
			ft_lstpush(list, ft_lstnew(num));
			elem++;
		}
	}
	return (elem);
}
