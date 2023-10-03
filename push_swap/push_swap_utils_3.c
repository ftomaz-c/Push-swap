/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:51:10 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/09/26 16:12:57 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(int size, t_list *head)
{
	int		min;
	t_list	*current;
	int		i;

	min = INT_MAX;
	current = head;
	i = 0;
	while (i < size)
	{
		if (current->data < min)
			min = current->data;
		current = current->next;
		i++;
	}
	return (min);
}

int	find_max(t_list *head)
{
	int		max;
	t_list	*current;

	max = INT_MIN;
	current = head;
	while (current)
	{
		if (current->data > max)
			max = current->data;
		current = current->next;
		if (current == head)
			break ;
	}
	return (max);
}

int	get_index(t_list *head, int data)
{
	int	count;
	t_list	*current;

	current = head;
	count = 0;
	while (current)
	{
		if (current->data == data)
			return (count);
		else
			count++;
		current = current->next;
		if (current == head)
			return (0) ;
	}
	return (0);
}

int	*create_tab(int size, t_list *head)
{
	int		*tab;
	t_list	*current;
	int		i;

	tab = malloc(sizeof(int) * size);
	if (!tab)
		return (NULL);
	current = head;
	i = 0;
	while (i < size)
	{
		tab[i] = current->data;
		current = current->next;
		i++;
	}
	return (tab);
}

int	*sort_tab(int size, t_list *head)
{
	int	*tab;

	tab = create_tab(size, head);
	if (!tab)
		return (NULL);
	quick_sort(tab, 0, size - 1);
	return (tab);
}
