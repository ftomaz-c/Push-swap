/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_push_swap_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:23:08 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/10/03 16:24:20 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*get_target(t_list *head_a, int data)
{
	t_list	*current;
	t_list	*target;
	int		min;
	int		i;
	int		size;

	size = stack_size(head_a);
	current = head_a;
	target = NULL;
	i = 0;
	if (data < (min = find_min(size, head_a)) || data > find_max(head_a))
	{
		while(current->data != min)
			current = current->next;
		target = current;
		return (target);
	}
	while (i < size)
	{
		if (current->data > data && current->prev->data < data)
		{
			target = current;
			return (target);
		}
		current = current->next;
		i++;
	}
	return(NULL);
}

void	reset_costs(t_list **current)
{
	(*current)->move_flags.move_down = 0;
	(*current)->move_flags.move_target_down = 0;
	(*current)->move_flags.move_target_up = 0;
	(*current)->move_flags.move_up = 0;
	(*current)->move_flags.moves = 0;
	(*current)->move_costs.down_cost = 0;
	(*current)->move_costs.down_target_cost = 0;
	(*current)->move_costs.total_cost = 0;
	(*current)->move_costs.up_cost = 0;
	(*current)->move_costs.up_target_cost = 0;
}

void	set_costs(t_list **current, t_list *head_a, t_list *head_b)
{
	int		size;

	reset_costs(current);
	size = stack_size(head_b);
	if ((*current)->position > size / 2)
	{
		(*current)->move_costs.down_cost = size - (*current)->position;
		(*current)->move_flags.move_down = 1;
	}
	else if ((*current)->position <= size / 2 && (*current)->position != 0)
	{
		(*current)->move_costs.up_cost = (*current)->position;
		(*current)->move_flags.move_up = 1;
	}
	size = stack_size(head_a);
	if ((*current)->target->position > size / 2)
	{
		(*current)->move_costs.down_target_cost
		= size - (*current)->target->position;
		(*current)->move_flags.move_target_down = 1;
	}
	else if ((*current)->target->position
	<= size / 2 && (*current)->target->position != 0)
	{
		(*current)->move_costs.up_target_cost = (*current)->target->position;
		(*current)->move_flags.move_target_up = 1;
	}
}

void	set_moves(t_list **current)
{
	if (((*current)->move_flags.move_down == 1
	|| (*current)->move_flags.move_target_down == 1)
	&& ((*current)->move_flags.move_up == 0
	&& (*current)->move_flags.move_target_up == 0))
		(*current)->move_flags.moves = DOWNDOWN;
	else if (((*current)->move_flags.move_up == 1
	|| (*current)->move_flags.move_target_up == 1)
	&& ((*current)->move_flags.move_down == 0
	&& (*current)->move_flags.move_target_down == 0))
		(*current)->move_flags.moves = UPUP;
	else if ((*current)->move_flags.move_down
	&& (*current)->move_flags.move_target_up)
		(*current)->move_flags.moves = DOWNUP;
	else if ((*current)->move_flags.move_up
	&& (*current)->move_flags.move_target_down)
		(*current)->move_flags.moves = UPDOWN;
}

void	refresh_info(t_list **head_a, t_list **head_b)
{
	t_list	*current;
	int		size;
	int		i;

	size = stack_size(*head_b);
	i = 0;
	current = *head_b;
	while (i < size)
	{
		current->target = get_target(*head_a, current->data);
		current->position = get_index(*head_b, current->data);
		current->target->position
		= get_index(*head_a, current->target->data);
		set_costs(&current, *head_a, *head_b);
		set_moves(&current);
		current->move_costs.total_cost
		= current->move_costs.down_cost + current->move_costs.up_cost
		+ current->move_costs.down_target_cost
		+ current->move_costs.up_target_cost;
		current = current->next;
		i++;
	}
}
