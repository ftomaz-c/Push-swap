/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:14:17 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/11/01 16:56:00 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Checks if it is in order and, according to the size of the stack A,
 * initializes the sort small_stack for <= 5 or big_stack for > 5.
 * In the small_stack, it sorts according to the size of the stack.
 * Same for the big_stack:
 * 	If the size is <= 10 it runs the simple sort;
 * 	If the size is <= 100 it pushes everything to stack B until there's only
 * 3 elements, sorts them, and runs the complex_sort_1;
 * 	If the size is > 100 it runs the complex_sort;
 */

#include "push_swap.h"

void	small_stack(int size, t_list **head_a, t_list **head_b)
{
	if (size == 2)
		two_element_sort(head_a, head_b);
	else if (size == 3)
		three_element_sort(head_a, head_b);
	else
		four_five_element_sort(head_a, head_b);
}

void	big_stack(int size, t_list **head_a, t_list **head_b)
{
	if (size <= 10)
	{
		simple_sort(head_a, head_b);
		while ((*head_b) != NULL)
			push(PA, head_a, head_b);
	}
	else if (size > 10 && size <= 100)
	{
		while (stack_size(*head_a) != 3)
			push(PB, head_a, head_b);
		small_stack(3, head_a, head_b);
		complex_sort_1(head_a, head_b);
	}
	else if (size > 100)
		complex_sort(size, head_a, head_b);
}

void	init_sort(t_list **head_a, t_list **head_b)
{
	int	size;

	size = 0;
	if (is_in_order(*head_a))
		return ;
	size = stack_size(*head_a);
	if (size <= 5)
		small_stack(size, head_a, head_b);
	else if (size > 5)
		big_stack(size, head_a, head_b);
}
