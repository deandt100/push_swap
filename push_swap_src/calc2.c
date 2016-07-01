/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 08:13:42 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/30 16:45:31 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		smallest(t_list *list, int *pos)
{
	int	small;
	int	i;

	small = *(int*)list->data;
	i = 0;
	while (list)
	{
		if (*(int*)list->data < small)
		{
			small = *(int*)list->data;
			*pos = i;
		}
		list = list->next;
		i++;
	}
	return (small);
}

void	sort_arr(int *arr, int elem)
{
	int	*ptr;
	int	swapped;
	int	i;
	int	temp;

	swapped = 1;
	i = 0;
	ptr = arr;
	while (swapped)
	{
		swapped = 0;
		i = 0;
		while (i + 1 < elem)
		{
			if (ptr[i] > ptr[i + 1])
			{
				temp = ptr[i];
				ptr[i] = ptr[i + 1];
				ptr[i + 1] = temp;
				swapped = 1;
			}
			i++;
		}
	}
}

int		median(t_info *info)
{
	int		*list;
	int		i;
	int		ret;
	t_list	*trav;

	list = (int*)malloc(sizeof(int) * info->max);
	if (list != NULL)
	{
		trav = info->a;
		i = 0;
		while (trav != NULL)
		{
			list[i] = *(int*)trav->data;
			trav = trav->next;
			i++;
		}
		sort_arr(list, info->max);
		get_optimal(info, list);
		i = 0;
		ret = list[info->max / 2];
		free(list);
		return (ret);
	}
	return (-1);
}

int		c_wave(t_list *stack)
{
	int		ret;
	t_list	*trav;

	trav = stack;
	ret = 0;
	if (trav != NULL)
	{
		while (trav->next != NULL)
		{
			if (*(int*)trav->data > *(int*)trav->next->data)
				ret++;
			trav = trav->next;
		}
	}
	return (ret);
}

int		c_wave_rev(t_list *stack)
{
	int		ret;
	t_list	*trav;

	trav = stack;
	ret = 0;
	if (trav != NULL)
	{
		while (trav->next != NULL)
		{
			if (*(int*)trav->data < *(int*)trav->next->data)
				ret++;
			trav = trav->next;
		}
	}
	return (ret);
}
