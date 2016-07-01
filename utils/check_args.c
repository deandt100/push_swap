/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 15:27:34 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/30 16:48:33 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_src/checker.h"

int		has_white(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

void	free_nums(char **nums)
{
	int i;

	i = 0;
	if (nums)
		while (nums[i])
			free(nums[i++]);
	free(nums);
}

int		check_args(int argc, char **argv)
{
	int		i;
	char	**nums;

	i = 0;
	if (argc == 2)
	{
		if (has_white(argv[1]))
		{
			nums = ft_strsplit(argv[1], ' ');
			while (nums[i])
				i++;
			if (i == 1)
				error_check(argc, argv);
			else
				error_check(i, nums);
			free_nums(nums);
		}
		return (i);
	}
	else
	{
		error_check(argc, argv);
		return (0);
	}
}
