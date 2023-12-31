/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:12:57 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/11/01 16:15:45 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Used to create a stack.
 * If it was created successfully it returns 1.
 */

#include "push_swap.h"

t_list	*create_node(int data)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->move_costs.up_cost = 0;
	new_node->move_costs.up_tg_cost = 0;
	new_node->move_costs.down_cost = 0;
	new_node->move_costs.down_tg_cost = 0;
	new_node->move_costs.total_cost = 0;
	new_node->move_flags.move_down = 0;
	new_node->move_flags.move_up = 0;
	new_node->move_flags.move_tg_down = 0;
	new_node->move_flags.move_tg_up = 0;
	new_node->move_flags.moves = 0;
	new_node->tg = NULL;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

int	add_node_to_stack(t_list **head_a, int data)
{
	t_list	*tmp;
	t_list	*last_node;

	tmp = create_node(data);
	if (!tmp)
		return (1);
	if (!*head_a)
	{
		*head_a = tmp;
		tmp->next = tmp;
		tmp->prev = tmp;
		return (0);
	}
	last_node = (*head_a)->prev;
	last_node->next = tmp;
	tmp->prev = last_node;
	tmp->next = *head_a;
	(*head_a)->prev = tmp;
	return (0);
}

int	stack_init(t_list **head_a, char **argv, int argc)
{
	int	index;

	index = 0;
	while (index < argc)
	{
		if (add_node_to_stack(head_a, ft_atoi(argv[index])))
		{
			free_nodes(*head_a);
			return (1);
		}
		index++;
	}
	return (0);
}

int	create_stack(int argc, char **argv, t_list **head_a)
{
	if (stack_init(head_a, argv, argc))
	{
		free_argv(argv);
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	free_argv(argv);
	return (1);
}
