/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:54:06 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/09/19 03:38:04 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void find_two_smallest_elements(t_list *head, int *first_small, int *second_small)
// {
// 	t_list	*current;

// 	*first_small = INT_MAX;
// 	*second_small = INT_MAX;
// 	current = head;
// 	while (current)
// 	{
// 		if (current->data < *first_small)
// 		{
// 			*second_small = *first_small;
// 			*first_small = current->data;
// 		}
// 		else if (current->data > *first_small && current->data < *second_small)
// 			*second_small = current->data;
// 		if (current->next == head)
// 			break;
// 		current = current->next;
// 	}
// }

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

// void	four_five_element_sort(int	size, t_list **head_a, t_list **head_b)
// {
// 	int	first_small;
// 	int	second_small;

// 	find_two_smallest_elements(*head_a, &first_small, &second_small);
// 	while ((*head_a)->data != first_small && (*head_a)->data != second_small)
// 		rotate(RA, head_a, head_b);
// 	push(PB, head_a, head_b);
// 	while ((*head_a)->data != first_small && (*head_a)->data != second_small)
// 		rotate(RA, head_a, head_b);
// 	push(PB, head_a, head_b);
// 	if ((*head_b)->data < (*head_b)->next->data)
// 		swap(SB, head_a, head_b);
// 	if (size == 4)
// 	{
// 		if ((*head_a)->data > (*head_a)->next->data)
// 			swap(SA, head_a, head_b);
// 	}
// 	if (size == 5)
// 		three_element_sort(head_a, head_b);
// 	push(PA, head_a, head_b);
// 	push(PA, head_a, head_b);
// 	while (!is_in_order(*head_a))
// 		rotate(RA, head_a, head_b);
// }

void	small_stack(int	size, t_list **head_a, t_list **head_b)
{
	if (size == 3)
		three_element_sort(head_a, head_b);
	// else if (size > 3)
	// 	four_five_element_sort(size, head_a, head_b);
}
