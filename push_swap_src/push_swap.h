/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 14:15:52 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/07/01 15:00:04 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../checker_src/checker.h"

/*
** Stored values for an algorithm - copies of stacks, number of operations
** it took to sort.
*/

typedef struct	s_option
{
	int	function;
	int	diff;
}				t_opt;

typedef struct	s_algo
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		elem_a;
	int		elem_b;
	t_list	*operations;
	int		op_count;
	int		max;
	int		valid;
	t_diff	*diffs;
}				t_algo;

/*
** Output functions
*/

void			compress_ops(t_list *ops, int *op_count);

void			print_steps(t_list *steps);

/*
** Other Stuff / norm functions
*/

void			do_best6(t_info *info, int i, int save);

void			delete_mask(t_info *info);

void			delete_algo(t_algo **src);

void			rollback_sort(t_info *info);

int				smallest(t_list *list, int *pos);

void			init_info(t_info *info);

t_algo			*new_algo(t_info *info);

int				c_wave(t_list *stack);

int				c_wave_rev(t_list *stack);

/*
** Sorting algoritms
*/

void			split_sort(t_algo *algo, t_info *info);

int				stack_sorted(t_list *stack);

int				stack_sorted_desc(t_list *stack);

int				dumb_sort(t_algo *algo, t_info *info);

void			bubble_sort(t_algo *algo, t_info *info);

t_info			*weight_sort(t_info *info);

/*
** Set values of algo contents for each function
*/

void			sa(t_algo *algo);

void			sb(t_algo *algo);

void			ss(t_algo *algo);

void			ra(t_algo *algo);

void			rb(t_algo *algo);

void			rr(t_algo *algo);

void			rra(t_algo *algo);

void			rrb(t_algo *algo);

void			rrr(t_algo *algo);

void			pa(t_algo *algo);

void			pb(t_algo *algo);

#endif
