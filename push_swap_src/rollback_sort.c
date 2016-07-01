/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rollback_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 11:28:54 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/30 15:14:10 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		count_valid(t_diff *diffs)
{
	int valid;

	valid = 11;
	valid -= (2147483647 == diffs->sa);
	valid -= (2147483647 == diffs->sb);
	valid -= (2147483647 == diffs->ss);
	valid -= (2147483647 == diffs->ra);
	valid -= (2147483647 == diffs->rb);
	valid -= (2147483647 == diffs->rr);
	valid -= (2147483647 == diffs->rra);
	valid -= (2147483647 == diffs->rrb);
	valid -= (2147483647 == diffs->rrr);
	valid -= (2147483647 == diffs->pa);
	valid -= (2147483647 == diffs->pb);
	return (valid);
}

int		pick_option(t_opt *options, int option_c)
{
	int i;
	int	small;

	i = 0;
	small = 0;
	while (i < option_c)
	{
		if (options[i].diff < options[small].diff)
			small = i;
		i++;
	}
	return (options[small].function);
}

/*
** Assess moves options and save int array op t_opt (s_options)
*/

int		get_options(int valid, int moves_done, t_info *mask, t_opt **options)
{
	int		cur_move;
	int		option_c;
	t_opt	*opt;

	opt = (t_opt*)malloc(sizeof(t_opt) * 11);
	option_c = 0;
	while (valid > 0 && moves_done > 1)
	{
		cur_move = get_best(mask);
		opt[option_c].diff = try_next(mask, 3, cur_move, &moves_done);
		opt[option_c].function = cur_move;
		do_function(mask->diffs, cur_move, &set_to_max);
		valid = count_valid(mask->diffs);
		option_c++;
	}
	*options = opt;
	return (option_c);
}

/*
** Attempt a few moves and assess effect on stack -
** rolls back changes and picks 'best' option
*/

void	rollback_sort(t_info *info)
{
	int		valid;
	int		option_c;
	t_opt	*options;
	int		moves_done;
	t_info	mask;

	ft_strcpy(info->diffs->last_a, "qq");
	ft_strcpy(info->diffs->last_b, "qq");
	info->choice_diff = calc_total_sortdiff(info);
	while (calc_total_sortdiff(info) != 0 && info->elem_steps < info->in_count)
	{
		valid = count_valid(info->diffs);
		do_tests(info);
		info_mask(info, &mask);
		moves_done = 42;
		option_c = get_options(valid, moves_done, &mask, &options);
		do_best(info, pick_option(options, option_c), 1);
		if (options)
			free(options);
	}
}
