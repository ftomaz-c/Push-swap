/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:48:37 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/09/14 11:20:53 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_node(int data)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->data = data;
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

	index = 1;
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
