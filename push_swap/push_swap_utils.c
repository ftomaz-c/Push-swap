/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:36:24 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/09/12 16:56:23 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_not_organized(t_list *head)
{
	if (head->data > head->next->data
		|| head->data > head->prev->data
		|| head->next->data > head->prev->data)
		return (1);
	return (0);
}

void	print_stack(t_list *head, char *label)
{
	t_list *current;

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
			break;
	}
	ft_printf("\n");
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

int	size(t_list *head)
{
	int		count;
	t_list	*current;

	if (!head)
		return (0);
	current = head;
	count = 0;
	while (current != NULL)
	{
		count++;
		current = current->next;
		if (current == head)
			break ;
	}
	return (count);
}
