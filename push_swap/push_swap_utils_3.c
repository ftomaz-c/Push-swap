/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:58:41 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/09/25 17:59:39 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	determine_partitions(int stack_size)
{
	if (stack_size <= 10)
		return (1);
	else if (stack_size <= 100)
		return (4);
	else
		return (8);
}

int	median(int size)
{
	int	median;

	median = 0;
	if (determine_partitions(size) == 4)
		median = size / 8;
	else if (determine_partitions(size) == 8)
		median = size / 16;
	return (median);
}
