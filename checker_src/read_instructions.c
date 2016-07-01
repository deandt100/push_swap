/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 14:20:27 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/07/01 14:44:40 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		cont_parse(char *line, t_info *info)
{
	if (ft_strcmp(line, "rrb") == 0)
	{
		ft_lstrotrev(&(info->b), info->elem_b);
		info->last_move = RRB;
	}
	else if (ft_strcmp(line, "rrr") == 0)
	{
		ft_lstrotrev(&(info->a), info->elem_a);
		ft_lstrotrev(&(info->b), info->elem_b);
		info->last_move = RRR;
	}
	else if (ft_strcmp(line, "rb") == 0)
	{
		ft_lstrot(&(info->b), info->elem_b);
		info->last_move = RB;
	}
	else
		return (-1);
	return (1);
}

int		parse_instruction2(char *line, t_info *info)
{
	if (ft_strcmp(line, "pb") == 0)
	{
		ft_lstpushpop(&(info->a), &(info->b));
		inc_elems(info, 0);
		info->last_move = PB;
	}
	else if (ft_strcmp(line, "ra") == 0)
	{
		ft_lstrot(&(info->a), info->elem_a);
		info->last_move = RA;
	}
	else if (ft_strcmp(line, "rr") == 0)
	{
		ft_lstrot(&(info->a), info->elem_a);
		ft_lstrot(&(info->b), info->elem_b);
		info->last_move = RR;
	}
	else if (ft_strcmp(line, "rra") == 0)
	{
		ft_lstrotrev(&(info->a), info->elem_a);
		info->last_move = RRA;
	}
	else
		return (cont_parse(line, info));
	return (1);
}

int		parse_instruction(char *line, t_info *info)
{
	if (ft_strcmp(line, "sa") == 0)
	{
		ft_lstswap(info->a);
		info->last_move = SA;
	}
	else if (ft_strcmp(line, "sb") == 0)
	{
		ft_lstswap(info->b);
		info->last_move = SB;
	}
	else if (ft_strcmp(line, "ss") == 0)
	{
		ft_lstswap(info->a);
		ft_lstswap(info->b);
		info->last_move = SS;
	}
	else if (ft_strcmp(line, "pa") == 0)
	{
		ft_lstpushpop(&(info->b), &(info->a));
		inc_elems(info, 1);
		info->last_move = PA;
	}
	else
		return (parse_instruction2(line, info));
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
				ft_printf("Recieved : \x1b[32m%s\n\x1b[0m", line);
				print_stacks(info->a, info->b, info);
				ft_putchar('\n');
			}
			free(line);
		}
	}
	return (ret);
}
