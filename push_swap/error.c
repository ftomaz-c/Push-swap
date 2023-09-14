/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:46:36 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/09/14 11:16:34 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_only_digits(char *arg)
{
	int	i;

	i = 0;
	while(arg[i] != '\0')
	{
		if (!ft_isdigit(arg[i]))
			return (1);
		i++;
	}
	return (0);
}

int	is_within_range(char *arg)
{
	long	num;

	num = ft_atol(arg);
	return (num > INT_MAX || num < INT_MIN);
}

int	has_duplicates(int argc, char **argv)
{
	int	index1;
	int	index2;

	index1 = 1;
	while (index1 < argc)
	{
		index2 = index1 + 1;
		while (index2 < argc)
		{
			if (ft_atoi(argv[index1]) == ft_atoi(argv[index2]))
				return (1);
			index2++;
		}
		index1++;
	}
	return (0);
}

int	error_arg_type(int argc, char **argv)
{
	int		index;

	index = 1;
	while (index < argc)
	{
		if (has_only_digits(argv[index]) || is_within_range(argv[index]))
			return (1);
		index++;
	}
	return (has_duplicates(argc, argv));
}
