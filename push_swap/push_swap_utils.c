/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:36:24 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/09/07 15:54:24 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
