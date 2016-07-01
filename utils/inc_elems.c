/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inc_elems.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 10:32:22 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/30 16:49:37 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_src/checker.h"

void	inc_elems(t_info *info, int order)
{
	if (order == 0)
	{
		if (info->elem_a > 0)
			info->elem_a--;
		if (info->elem_b < info->max)
			info->elem_b++;
	}
	if (order == 1)
	{
		if (info->elem_b > 0)
			info->elem_b--;
		if (info->elem_a < info->max)
			info->elem_a++;
	}
}
