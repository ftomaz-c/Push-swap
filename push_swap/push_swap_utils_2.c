/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:36:24 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/11/01 16:46:35 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_in_order(t_list *head)
{
	t_list	*current;

	current = head;
	while (current)
	{
		if (current->data > current->next->data)
			return (0);
		current = current->next;
		if (current->next == head)
			break ;
	}
	return (1);
}


void	free_nodes(t_list *a)
{
	t_list	*current;
	t_list	*temp;

	if (!a)
		return ;
	current = a->next;
	while (current != a)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	free(a);
}

int	stack_size(t_list *head)
{
	int		count;
	t_list	*current;

	if (!head)
		return (0);
	current = head->next;
	count = 1;
	while (current != head)
	{
		count++;
		current = current->next;
	}
	return (count);
}

/* void	print_stack(t_list *head, char *label)
{
	t_list	*current;

	current = head;
	ft_printf("Stack %s: ", label);
	if (!head)
	{
		ft_printf("(null)\n");
		return ;
	}
	while (current->next != NULL)
	{
		ft_printf("%d ", current->data);
		current = current->next;
		if (current == head)
			break ;
	}
	ft_printf("\n");
} */
