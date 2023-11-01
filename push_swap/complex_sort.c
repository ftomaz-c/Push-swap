/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:21:17 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/11/01 15:49:21 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*get_cheapest(t_list **head_b)
{
	t_list	*current;
	t_list	*cheapest;
	int		total_cost;
	int		size;
	int		i;

	current = *head_b;
	total_cost = INT_MAX;
	size = stack_size(*head_b);
	i = 0;
	while (i++ < size)
	{
		if (current->move_costs.total_cost < total_cost)
		{
			cheapest = current;
			total_cost = current->move_costs.total_cost;
		}
		if (current->move_costs.total_cost == total_cost)
		{
			if (cheapest->data < current->data)
				cheapest = current;
		}
		current = current->next;
	}
	return (cheapest);
}

void	complex_sort(int size, t_list **head_a, t_list **head_b)
{
	int	key_position;

	key_position = size / 4;
	complex_partition(key_position, size, head_a, head_b);
	if (stack_size(*head_a) == 3)
		small_stack(3, head_a, head_b);
	else
		simple_sort(head_a, head_b);
	complex_sort_1(head_a, head_b);
}

void	partition(t_list **head_a, t_list **head_b, t_list *current, int median)
{
	int	index;
	int	size;

	size = stack_size(*head_a);
	index = get_index(*head_a, current->data);
	while ((*head_a)->data != current->data)
	{
		if (index > size / 2)
			reverse_rotate(RRA, head_a, head_b);
		else if (index <= size / 2)
			rotate(RA, head_a, head_b);
	}
	push(PB, head_a, head_b);
	if ((*head_b)->next)
	{
		if ((*head_b)->data >= median)
			rotate(RB, head_a, head_b);
	}
}

void	complex_partition(int idx, int size, t_list **head_a, t_list **head_b)
{
	int		key_median;
	t_list	*current;
	int		*sorted_array;

	sorted_array = sort_tab(stack_size(*head_a), *head_a);
	while (idx <= size)
	{
		key_median = sorted_array[idx - size / 8];
		current = *head_a;
		while (stack_size(*head_b) != idx - 3)
		{
			if (current->data <= sorted_array[idx - 1])
			{
				partition(head_a, head_b, current, key_median);
				if ((*head_a))
					current = *head_a;
			}
			else if (current->data > sorted_array[idx - 1])
				current = current->next;
		}
		idx += size / 4;
	}
	free (sorted_array);
	return ;
}

void	complex_sort_1(t_list **head_a, t_list **head_b)
{
	t_list	*current;
	int		min;
	int		index;
	int		size;

	while ((*head_b))
	{
		refresh_info(head_a, head_b);
		current = get_cheapest(head_b);
		make_moves(current, head_a, head_b);
		push(PA, head_a, head_b);
	}
	size = stack_size(*head_a);
	min = find_min(size, *head_a);
	index = get_index(*head_a, min);
	while ((*head_a)->data != min)
	{
		if (index > size / 2)
			reverse_rotate(RRA, head_a, head_b);
		else if (index <= size / 2)
			rotate(RA, head_a, head_b);
	}
}
