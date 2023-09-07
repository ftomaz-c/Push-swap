/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:46:36 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/09/07 16:36:30 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checks_digits(char *arg)
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

int	checks_range(char *arg)
{
	long	num;

	num = ft_atol(arg);
	if (num > INT_MAX || num < INT_MIN)
		return (1);
	return (0);
}

int	checks_duplicate(int argc, char **argv)
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
		if (checks_digits(argv[index]) ||
			checks_range(argv[index]) ||
			checks_duplicate(argc, argv))
			return (1);
		index++;
	}
	return (0);
}
