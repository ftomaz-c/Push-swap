/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:46:36 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/08/18 17:47:39 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_arg_type(int argc, char **argv)
{
	int		index1;
	int		index2;
	int		i;

	index1 = 1;
	while (index1 < argc)
	{
		i = 0;
		while (argv[index1][i] != '\0')
		{
			if (!(ft_isdigit(argv[index1][i])))
				return (1);
			i++;
		}
		if (ft_atol(argv[index1]) > INT_MAX || ft_atol(argv[index1]) < INT_MIN)
			return (1);
		index2 = index1 + 1;
		while (index2 < argc && ft_atoi(argv[index1]) != ft_atoi(argv[index2]))
			index2++;
		if (index2 < argc && ft_atoi(argv[index1]) == ft_atoi(argv[index2]))
			return (1);
		index1++;
	}
	return (0);
}
