/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 11:53:38 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/30 08:23:44 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	validate(t_info *info)
{
	int		i;
	t_list	*crawl;

	i = 0;
	crawl = info->a;
	while (crawl != NULL)
	{
		if (crawl->next != NULL)
		{
			if (*(int *)crawl->data >= *(int *)crawl->next->data)
			{
				ft_printf("KO\n");
				return (1);
			}
		}
		crawl = crawl->next;
		i++;
	}
	if (i > info->max || info->elem_b != 0)
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	return (1);
}
