/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 02:46:57 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/10/03 16:27:01 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_stack(int size, t_list **head_a, t_list **head_b)
{
	int	current_index;
	int	*sorted_array;

	if (size <= 10)
		simple_sort(head_a, head_b);
	else if (size > 10 && size <= 100)
	{
		while (stack_size(*head_a) != 3)
			push(PB, head_a, head_b);
		small_stack(3, head_a, head_b);
		complex_sort_2(head_a, head_b);
	}
	else if (size > 100)
	{
		sorted_array = sort_tab(size, *head_a);
		current_index = size / 4;
		complex_sort_1(current_index, size, head_a, head_b, sorted_array);
		free (sorted_array);
		small_stack(3, head_a, head_b);
		complex_sort_2(head_a, head_b);
	}
}

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
	while ((*head_b) != NULL)
		push(PA, head_a, head_b);
}
