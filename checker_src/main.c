/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 09:41:51 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/30 17:01:31 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	init_info(t_info *info)
{
	info->elem_a = 0;
	info->elem_b = 0;
	info->elem_steps = 0;
	info->b = NULL;
	info->a = NULL;
	info->v_mode = 0;
	info->v_pos = -1;
}

char	**copy_argv(int argc, char **argv, t_info *info)
{
	char	**new_argv;
	int		i;
	int		a;

	a = 0;
	new_argv = NULL;
	if (info->v_mode == 1)
	{
		new_argv = (char**)malloc(sizeof(char*) * argc - 1);
		i = 0;
		while (a < argc)
		{
			if (a != info->v_pos)
			{
				new_argv[i] = ft_strdup(argv[a]);
				i++;
			}
			a++;
		}
	}
	return (new_argv);
}

void	set_visual(int argc, char **argv, t_info *info)
{
	int		i;

	i = 0;
	while (i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == 'v' && argv[i][2] == '\0')
		{
			info->v_mode = 1;
			info->v_pos = i;
		}
		i++;
	}
}

void	fill_stack_a(int argc, char **ar, int n, t_info *info)
{
	if (n)
		info->elem_a = store_stack(&info->a, n, ft_strsplit(ar[1], ' '), !(n));
	else
		info->elem_a = store_stack(&info->a, argc, ar, !(n));
}

int		main(int argc, char **argv)
{
	t_info	info;
	int		n;
	char	**ar_cp;

	init_info(&info);
	set_visual(argc, argv, &info);
	if (info.v_mode == 0)
	{
		n = check_args(argc, argv);
		fill_stack_a(argc, argv, n, &info);
	}
	else
	{
		ar_cp = copy_argv(argc, argv, &info);
		argc--;
		n = check_args(argc, ar_cp);
		fill_stack_a(argc, ar_cp, n, &info);
	}
	info.max = info.elem_a;
	check_dup(info.a);
	if (info.v_mode == 1)
		print_stacks(info.a, info.b, &info);
	get_next_instruction(&info);
	validate(&info);
	return (0);
}
