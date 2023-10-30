/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_moves_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:21:07 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/10/30 18:21:01 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	upup(t_list *current, t_list **head_a, t_list **head_b)
{
	int	cost_b;
	int	cost_target;

	cost_b = current->move_costs.up_cost;
	cost_target = current->move_costs.up_tg_cost;
	while (cost_target > 0 && cost_b > 0)
	{
		rotate(RR, head_a, head_b);
		cost_target--;
		cost_b--;
	}
	while (cost_target > 0)
	{
		rotate(RA, head_a, head_b);
		cost_target--;
	}
	while (cost_b > 0)
	{
		rotate(RB, head_a, head_b);
		cost_b--;
	}
}

void	downdown(t_list *current, t_list **head_a, t_list **head_b)
{
	int	cost_b;
	int	cost_target;

	cost_b = current->move_costs.down_cost;
	cost_target = current->move_costs.down_tg_cost;
	while (cost_target > 0 && cost_b > 0)
	{
		reverse_rotate(RRR, head_a, head_b);
		cost_target--;
		cost_b--;
	}
	while (cost_target > 0)
	{
		reverse_rotate(RRA, head_a, head_b);
		cost_target--;
	}
	while (cost_b > 0)
	{
		reverse_rotate(RRB, head_a, head_b);
		cost_b--;
	}
}

void	downup(t_list *current, t_list **head_a, t_list **head_b)
{
	int	cost_b;
	int	cost_target;

	cost_b = current->move_costs.down_cost;
	cost_target = current->move_costs.up_tg_cost;
	while (cost_b > 0)
	{
		reverse_rotate(RRB, head_a, head_b);
		cost_b--;
	}
	while (cost_target > 0)
	{
		rotate(RA, head_a, head_b);
		cost_target--;
	}
}

void	updown(t_list *current, t_list **head_a, t_list **head_b)
{
	int	cost_b;
	int	cost_target;

	cost_b = current->move_costs.up_cost;
	cost_target = current->move_costs.down_tg_cost;
	while (cost_b > 0)
	{
		rotate(RB, head_a, head_b);
		cost_b--;
	}
	while (cost_target > 0)
	{
		reverse_rotate(RRA, head_a, head_b);
		cost_target--;
	}
}

void	make_moves(t_list *current, t_list **head_a, t_list **head_b)
{
	if (current->move_flags.moves == DOWNDOWN)
		downdown(current, head_a, head_b);
	else if (current->move_flags.moves == UPUP)
		upup(current, head_a, head_b);
	else if (current->move_flags.moves == DOWNUP)
		downup(current, head_a, head_b);
	else if (current->move_flags.moves == UPDOWN)
		updown(current, head_a, head_b);
	return ;
}
