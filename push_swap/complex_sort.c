/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:21:17 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/10/30 18:05:01 by ftomaz-c         ###   ########.fr       */
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
	int	current_index;
	int	*sorted_array;

	sorted_array = sort_tab(size, *head_a);
	current_index = size / 4;
	complex_sort_1(current_index, size, head_a, head_b, sorted_array);
	free (sorted_array);
	if (stack_size(*head_a) == 3)
		small_stack(3, head_a, head_b);
	else
		simple_sort(head_a, head_b);
	complex_sort_2(head_a, head_b);
}

void	complex_sort_1(int idx, int size, t_list **head_a, t_list **head_b, int *tab)
{
	int		key_nbr;
	int		index;
	int		count;
	int		key_median;
	t_list	*current;

	key_median = tab[idx - size / 8];
	key_nbr = tab[idx - 1];
	current = *head_a;
	count = 0;
	while (stack_size(*head_b) != idx - 3)
	{
		if (current->data <= key_nbr)
		{
			index = get_index(*head_a, current->data);
			while ((*head_a)->data != current->data)
			{
				if (index > size / 2)
					reverse_rotate(RRA, head_a, head_b);
				else if (index <= size / 2)
					rotate(RA, head_a, head_b);
			}
			push(PB, head_a, head_b);
			count++;
			if ((*head_b)->next && count > 1)
			{
				if ((*head_b)->data >= key_median)
					rotate(RB, head_a, head_b);
				/* else if ((*head_b)->data < key_median)
					swap(SB, head_a, head_b); */
			}
			if ((*head_a))
				current = *head_a;
		}
		else if (current->data > key_nbr)
			current = current->next;
	}
	idx += size / 4;
	if (idx <= size)
		complex_sort_1(idx, size, head_a, head_b, tab);
	return ;
}

void	complex_sort_2(t_list **head_a, t_list **head_b)
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

	// ft_printf("|data	%d|\n", current->data);
	// ft_printf("--------------------------\n");
	// ft_printf("up_cost			%d\n", current->up_cost);
	// ft_printf("up_target_cost		%d\n", current->up_target_cost);
	// ft_printf("down_cost		%d\n", current->down_cost);
	// ft_printf("down_target_cost	%d\n", current->down_target_cost);
	// ft_printf("total_cost		%d\n", current->total_cost);
	// ft_printf("position		%d\n", current->position);
	// ft_printf("target_position		%d\n", current->target->position);
	// ft_printf("move_up			%d\n", current->move_up);
	// ft_printf("move_down		%d\n", current->move_down);
	// ft_printf("move_target_up		%d\n", current->move_target_up);
	// ft_printf("move_target_down	%d\n", current->move_target_down);
	// ft_printf("--------------------------\n");
	// ft_printf("\n-------------------------\n");
	// ft_printf("\n");
	// print_stack(*head_a, "A");
	// ft_printf("\n");
	// print_stack(*head_b, "B");
	// ft_printf("\n");
	// ft_printf("-------------------------\n");

	// ft_printf("|data	%d|\n", current->data);
	// ft_printf("--------------------------\n");
	// ft_printf("up_cost			%d\n", current->move_costs.up_cost);
	// ft_printf("up_target_cost		%d\n", current->move_costs.up_target_cost);
	// ft_printf("down_cost		%d\n", current->move_costs.down_cost);
	// ft_printf("down_target_cost	%d\n", current->move_costs.down_target_cost);
	// ft_printf("total_cost		%d\n", current->move_costs.total_cost);
	// ft_printf("position		%d\n", current->position);
	// ft_printf("target_position		%d\n", current->target->position);
	// ft_printf("move_up			%d\n", current->move_flags.move_up);
	// ft_printf("move_down		%d\n", current->move_flags.move_down);
	// ft_printf("move_target_up		%d\n", current->move_flags.move_target_up);
	// ft_printf("move_target_down	%d\n", current->move_flags.move_target_down);
	// ft_printf("moves	%d\n", current->move_flags.moves);
	// ft_printf("--------------------------\n");
