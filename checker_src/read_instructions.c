/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 14:20:27 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/07/01 08:25:21 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		cont_parse(char *line, t_info *info)
{
	if (ft_strcmp(line, "rr") == 0)
	{
		ft_lstrot(&(info->a), info->elem_a);
		ft_lstrot(&(info->b), info->elem_b);
	}
	else if (ft_strcmp(line, "rra") == 0)
	{
		ft_lstrotrev(&(info->a), info->elem_a);
	}
	else if (ft_strcmp(line, "rrb") == 0)
		ft_lstrotrev(&(info->b), info->elem_b);
	else if (ft_strcmp(line, "rrr") == 0)
	{
		ft_lstrotrev(&(info->a), info->elem_a);
		ft_lstrotrev(&(info->b), info->elem_b);
	}
	else if (ft_strcmp(line, "rb") == 0)
		ft_lstrot(&(info->b), info->elem_b);
	else
		return (-1);
	return (1);
}

int		parse_instruction(char *line, t_info *info)
{
	if (ft_strcmp(line, "sa") == 0)
		ft_lstswap(info->a);
	else if (ft_strcmp(line, "sb") == 0)
		ft_lstswap(info->b);
	else if (ft_strcmp(line, "ss") == 0)
	{
		ft_lstswap(info->a);
		ft_lstswap(info->b);
	}
	else if (ft_strcmp(line, "pa") == 0)
	{
		ft_lstpushpop(&(info->b), &(info->a));
		inc_elems(info, 1);
	}
	else if (ft_strcmp(line, "pb") == 0)
	{
		ft_lstpushpop(&(info->a), &(info->b));
		inc_elems(info, 0);
	}
	else if (ft_strcmp(line, "ra") == 0)
		ft_lstrot(&(info->a), info->elem_a);
	else
		return (cont_parse(line, info));
	return (1);
}

void	ok_print(void)
{
	ft_putendl("OK\n");
	exit(1);
}

int		get_next_instruction(t_info *info)
{
	char	*line;
	int		ret;

	ret = 0;
	while (get_next_line(0, &line) == 1)
	{
		if (line != NULL)
		{
			ret = parse_instruction(line, info);
			if (ret == -1)
				error_print();
			if (info->v_mode)
			{
				ft_printf("Recieved : %s\n", line);
				print_stacks(info->a, info->b, info);
				ft_putchar('\n');
			}
			free(line);
		}
	}
	return (ret);
}
