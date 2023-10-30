/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 19:30:03 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/10/30 18:30:14 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_operation(t_list **src, t_list **dest)
{
	t_list	*tmp;

	if (!src || !(*src))
		return ;
	tmp = *src;
	if ((*src)->next == *src && (*src)->prev == *src)
		*src = NULL;
	else
	{
		tmp->prev->next = tmp->next;
		tmp->next->prev = tmp->prev;
		*src = tmp->next;
	}
	if (*dest)
	{
		tmp->next = *dest;
		tmp->prev = (*dest)->prev;
		(*dest)->prev->next = tmp;
		(*dest)->prev = tmp;
	}
	else
	{
		tmp->next = tmp;
		tmp->prev = tmp;
	}
	*dest = tmp;
}

void	pa(t_list **head_a, t_list **head_b)
{
	push_operation(head_b, head_a);
}

void	pb(t_list **head_a, t_list **head_b)
{
	push_operation(head_a, head_b);
}

void	push(char *op, t_list **head_a, t_list **head_b)
{
	if (ft_strncmp(op, PA, 2) == 0)
	{
		pa(head_a, head_b);
		ft_printf("pa\n");
	}
	else if (ft_strncmp(op, PB, 2) == 0)
	{
		pb(head_a, head_b);
		ft_printf("pb\n");
	}
}

