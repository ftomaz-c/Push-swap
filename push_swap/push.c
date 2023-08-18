/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 19:30:03 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/08/18 20:07:11 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_list **head_a, t_list **head_b)
{
	t_list	*next;
	t_list	*previous;
	t_list	*tmp;

	next = (*head_a)->next;
	previous = (*head_a)->prev;
	tmp = *head_a;
	next->prev = previous;
	previous->next = next;
	*head_a = next;
	*head_b = tmp;
}
