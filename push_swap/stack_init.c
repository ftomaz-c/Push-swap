/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:48:37 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/09/05 15:49:10 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_nodes(t_list *a)
{
	t_list	*current;
	t_list	*temp;

	current = a->next;
	while (current != a)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	free(a);
}

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

int	stack_init(t_list **head_a, char **argv, int argc)
{
	t_list	*temp;
	t_list	*current;
	int		index;

	index = 1;
	while (index < argc)
	{
		temp = create_node(ft_atoi(argv[index]), index);
		if (!temp)
		{
			free_nodes(*head_a);
			return (1);
		}
		if (*head_a == NULL)
		{
			*head_a = temp;
			current = temp;
		}
		else
		{
			current->next = temp;
			temp->prev = current;
			current = temp;
			current->next = *head_a;
			(*head_a)->prev = current;
		}
		index++;
	}
	return (0);
}
