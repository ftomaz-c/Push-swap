/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:11:20 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/10/30 17:12:22 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_sort(t_list **head_a, t_list **head_b)
{
	int	min_value;
	int	index;
	int	size;

	size = stack_size(*head_a);
	min_value = find_min(size, *head_a);
	index = get_index(*head_a, min_value);
	if (size == 3)
	{
		small_stack(3, head_a, head_b);
		return ;
	}
	while ((*head_a)->data != min_value)
	{
		if (index > size / 2)
			reverse_rotate(RRA, head_a, head_b);
		else
			rotate(RA, head_a, head_b);
	}
	push(PB, head_a, head_b);
	simple_sort(head_a, head_b);
}
