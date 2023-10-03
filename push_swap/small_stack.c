/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:54:06 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/09/28 17:03:18 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_element_sort(t_list **head_a, t_list **head_b)
{
	if ((*head_a)->data > (*head_a)->next->data)
		swap(SA, head_a, head_b);
}

void	three_element_sort(t_list **head_a, t_list **head_b)
{
	while (is_not_organized(*head_a))
	{
		if ((*head_a)->data > (*head_a)->next->data)
		{
			if ((*head_a)->next->data < (*head_a)->prev->data)
			{
				if ((*head_a)->data < (*head_a)->prev->data)
					swap(SA, head_a, head_b);
				else
					reverse_rotate(RRA, head_a, head_b);
				continue;
			}
			else
				swap(SA, head_a, head_b);
		}
		if ((*head_a)->data < (*head_a)->next->data)
			reverse_rotate(RRA, head_a, head_b);
	}
}

void	four_five_element_sort (t_list **head_a, t_list **head_b)
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

void	small_stack(int	size, t_list **head_a, t_list **head_b)
{
	if (size == 2)
		two_element_sort(head_a, head_b);
	else if (size == 3)
		three_element_sort(head_a, head_b);
	else
		four_five_element_sort(head_a, head_b);
}
