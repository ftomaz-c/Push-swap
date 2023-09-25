/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 02:46:57 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/09/22 19:24:30 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <math.h>

int	find_min(int size, t_list *head)
{
	int	min;
	t_list	*current;
	int	i;

	min = INT_MAX;
	current = head;
	i = 0;
	while(i < size)
	{
		if (current->data < min)
			min = current->data;
		current = current->next;
		i++;
	}
	return (min);
}

int	find_max(t_list *head)
{
	int	max;
	t_list	*current;

	max = INT_MIN;
	current = head;
	while(current)
	{
		if (current->data > max)
			max = current->data;
		current = current->next;
		if (current == head)
			break;
	}
	return (max);
}

int	get_index(t_list *head, int data)
{
	int	count;
	t_list	*current;

	current = head;
	count = 0;
	while (current)
	{
		if (current->data == data)
			break;
		count++;
		current = current->next;
		if (current == head)
			break;
	}
	return (count);
}

int	*create_tab(int size, t_list *head)
{
	int	*tab;
	t_list	*current;
	int	i;

	tab = malloc(sizeof(int) * size);
	if (!tab)
		return (NULL);
	current = head;
	i = 0;
	while (i < size)
	{
		tab[i] = current->data;
		current = current->next;
		i++;
	}
	return (tab);
}

int	*sort_tab(int size, t_list *head)
{
	int	*tab;

	tab = create_tab(size, head);
	if (!tab)
		return (NULL);
	quick_sort(tab, 0, size - 1);
	return (tab);
}

int determine_partitions(int stack_size)
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

	if (determine_partitions(size) == 4)
		median = size / 8;
	else if (determine_partitions(size) == 8)
		median = size / 16;
	return (median);
}

void	hundred_stack_sort(int idx, int size, t_list **head_a, t_list **head_b, int *tab)
{
	int	key_nbr;
	int	index;
	int	count;
	int	key_median;
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
			while((*head_a)->data != current->data)
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
		hundred_stack_sort(idx, size, head_a, head_b, tab);
	return;
}

void	big_stack(int size, t_list **head_a, t_list **head_b)
{
	int	current_index;
	int	*sorted_array;
	int	max;
	int	min;
	int	index;

	if (size <= 10)
	{
		ten_stack_sort(head_a, head_b);

	}
	else if (size > 10)
	{
		sorted_array = sort_tab(size, *head_a);
		current_index = size / determine_partitions(size);
		hundred_stack_sort(current_index, size, head_a, head_b, sorted_array);
		free (sorted_array);
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
		small_stack(3, head_a, head_b);

		// ft_printf("\n-------------------------\n");
		// ft_printf("\n");
		// print_stack(*head_a, "A");
		// ft_printf("\n");
		// print_stack(*head_b, "B");
		// ft_printf("\n");
		// ft_printf("-------------------------\n");

		while ((*head_b) != NULL)
		{
			size = stack_size (*head_b);
			max = find_max(*head_b);
			index = get_index(*head_b, max);
			while ((*head_b)->data != max)
			{
				if ((*head_b)->next->data == max)
					swap(SB, head_a, head_b);
				else if (index > size / 2)
					reverse_rotate(RRB, head_a, head_b);
				else
					rotate(RB, head_a, head_b);
			}
			push(PA, head_a, head_b);
		}
		// ft_printf("\n-------------------------\n");
		// ft_printf("\n");
		// print_stack(*head_a, "A");
		// ft_printf("\n");
		// print_stack(*head_b, "B");
		// ft_printf("\n");
		// ft_printf("-------------------------\n");
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
		return;
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
