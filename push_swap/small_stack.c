/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:54:06 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/11/01 17:32:16 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Organizes the stack for <= 5 numbers:
 *
 * 	The two_element_sort only swaps;
 * 	The three_element_sort sorts the 3 elements according to their position
 * in the stack.
 * 	The four_five_element_sort finds the smallest and Push to stack B until
 * there's only 3 elements inside the stack. This ensures that when pushed
 * back to A, they are in order.
 */

#include "push_swap.h"

void	two_element_sort(t_list **head_a, t_list **head_b)
{
	if ((*head_a)->data > (*head_a)->next->data)
		swap(SA, head_a, head_b);
}

void	three_element_sort(t_list **head_a, t_list **head_b)
{
	while (!is_in_order(*head_a))
	{
		if ((*head_a)->data > (*head_a)->next->data)
		{
			if ((*head_a)->next->data < (*head_a)->prev->data)
			{
				if ((*head_a)->data < (*head_a)->prev->data)
					swap(SA, head_a, head_b);
				else
					rotate(RA, head_a, head_b);
			}
			else
				rotate(RA, head_a, head_b);
		}
		else
			reverse_rotate(RRA, head_a, head_b);
	}
}

void	four_five_element_sort(t_list **head_a, t_list **head_b)
{
	int	min;
	int	index;
	int	size;

	while (stack_size(*head_a) != 3)
	{
		min = find_min(stack_size(*head_a), *head_a);
		index = get_index(*head_a, min);
		size = stack_size(*head_a);
		while ((*head_a)->data != min)
		{
			if (index > size / 2)
				reverse_rotate(RRA, head_a, head_b);
			else
				rotate(RA, head_a, head_b);
		}
		push(PB, head_a, head_b);
	}
	three_element_sort(head_a, head_b);
	while ((*head_b))
		push (PA, head_a, head_b);
}
