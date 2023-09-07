/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:48:37 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/09/07 15:38:51 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_node(int data, int index)
{
	t_list	*temp;

	temp = malloc(sizeof(t_list));
	if (!temp)
		return (NULL);
	temp->data = data;
	temp->index = index;
	temp->next = NULL;
	temp->prev = NULL;
	return (temp);
}

int	add_node_to_stack(t_list **head_a, int data, int index)
{
	t_list	*temp;
	t_list	*current;
	t_list	*last;

	temp = create_node(data, index);
	if (!temp)
		return (1);
	if (!*head_a)
	{
		*head_a = temp;
		temp->next = temp;
		temp->prev = temp;
		return (0);
	}
	last = (*head_a)->prev;
	last->next = temp;
	temp->prev = last;
	temp->next = *head_a;
	(*head_a)->prev = temp;
	return (0);
}

int	stack_init(t_list **head_a, char **argv, int argc)
{
	int	index;

	index = 1;
	while (index < argc)
	{
		if (add_node_to_stack(head_a, ft_atoi(argv[index]), index))
		{
			free_nodes(*head_a);
			return (1);
		}
		index++;
	}
	return (0);
}
