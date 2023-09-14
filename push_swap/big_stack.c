/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 10:16:07 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/09/14 15:58:04 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	find_pivot(t_list **head)
// {
// 	int		data_sum;
// 	int		count;
// 	t_list	*current;

// 	current = *head;
// 	data_sum = 0;
// 	count = 0;
// 	while (current)
// 	{
// 		data_sum += current->data;
// 		count++;
// 		current = current->next;
// 		if (current == *head)
// 			break;
// 	}
// 	return (data_sum / count);
// }

int	median_of_three(int a, int b, int c)
{
	if ((a <= b && b <= c) || (c <= b && b <= a))
		return b;
	if ((b <= a && a <= c) || (c <= a && a <= b))
		return a;
	return c;
}

int	find_pivot(int size, t_list *head_a)
{
	t_list	*current;
	int		count;
	int		first;
	int		last;
	int		middle;

	first = head_a->data;
	last = head_a->prev->data;
	count = 0;
	current = head_a;
	while (count < ((size - 1) / 2) - 1)
	{
		current = current->next;
		count++;
	}
	middle = current->data;
	return(median_of_three(first, middle, last));
}

void	split_stack(int size, int	pivot, t_list **head_a, t_list **head_b)
{
	int		count;
	t_list	*current;

	count = 0;
	current = *head_a;
	while (count < size)
	{
		if (current->data < pivot)
		{
			push(PB, head_a, head_b);
			current = *head_a;
		}
		else
		{
			rotate(RA, head_a, head_b);
			current = current->next;
		}
		count++;
	}
}

void	big_stack(t_list **head_a, t_list **head_b)
{
	int	pivot;
	int	size;

	size = stack_size(*head_a);
	pivot = find_pivot(size, *head_a);
	split_stack(size, pivot, head_a, head_b);
}
