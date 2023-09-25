/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 02:46:57 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/09/25 18:24:03 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_sort(int idx, int size, t_list **head_a, t_list **head_b, int *tab)
{
	int		key_nbr;
	int		index;
	int		count;
	int		key_median;
	t_list	*current;

	key_median = tab[idx - median(size)];
	key_nbr = tab[idx - 1];
	current = *head_a;
	count = 0;
	while (stack_size(*head_b) != idx)
	{
		if (current->data <= key_nbr)
		{
			index = get_index(*head_a, current->data);
			while ((*head_a)->data != current->data)
			{
				if (index > size / 2)
					reverse_rotate(RRA, head_a, head_b);
				else if (index < size / 2)
					rotate(RA, head_a, head_b);
			}
			push(PB, head_a, head_b);
			count++;
			if ((*head_b)->next && count > 1)
			{
				if ((*head_b)->data >= key_median)
					rotate(RB, head_a, head_b);
				else if ((*head_b)->data < key_median)
					swap(SB, head_a, head_b);
			}
			if ((*head_a))
				current = *head_a;
		}
		if (current->data > key_nbr)
			current = current->next;
	}
	idx += size / determine_partitions(size);
	if (idx <= size - size / determine_partitions(size))
		stack_sort(idx, size, head_a, head_b, tab);
	return ;
}

void	stack_sort_2(t_list **head_a, t_list **head_b)
{
	int	size;
	int	index;
	int	min;

	while (stack_size(*head_a) != 3)
	{
		size = stack_size(*head_a);
		min = find_min (size, *head_a);
		index = get_index(*head_a, min);
		while ((*head_a)->data != min)
		{
			if ((*head_a)->next->data == min)
				swap(SA, head_a, head_b);
			else if (index > size / 2)
				reverse_rotate(RRA, head_a, head_b);
			else
				rotate(RA, head_a, head_b);
		}
		push(PB, head_a, head_b);
	}
}

void	big_stack(int size, t_list **head_a, t_list **head_b)
{
	int	current_index;
	int	*sorted_array;

	if (size <= 10)
	{
		ten_stack_sort(head_a, head_b);
	}
	else if (size > 10)
	{
		sorted_array = sort_tab(size, *head_a);
		current_index = size / determine_partitions(size);
		stack_sort(current_index, size, head_a, head_b, sorted_array);
		free (sorted_array);
		stack_sort_2(head_a, head_b);
		small_stack(3, head_a, head_b);
		// stack_sort_3(head_a, head_b);
	}
}

void	ten_stack_sort(t_list **head_a, t_list **head_b)
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
	ten_stack_sort(head_a, head_b);
	while ((*head_b) != NULL)
		push(PA, head_a, head_b);
}
