/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 12:28:17 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/09/14 11:36:39 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_operation(t_list **head)
{
	int	tmp;

	if (!(*head) || !(*head)->next)
		return ;
	tmp = (*head)->data;
	(*head)->data = (*head)->next->data;
	(*head)->next->data = tmp;
}

void	sa(t_list **head_a)
{
	swap_operation(head_a);
}

void	sb(t_list **head_b)
{
	swap_operation(head_b);
}

void	ss(t_list **head_a, t_list **head_b)
{
	sa(head_a);
	sb(head_b);
}

void	swap(const char *op, t_list **head_a, t_list **head_b)
{
	if (ft_strncmp(op, SA, 2) == 0)
	{
		sa(head_a);
		ft_printf("sa\n");
	}
	else if (ft_strncmp(op, SB, 2) == 0)
	{
		sb(head_b);
		ft_printf("sb\n");
	}
	else if (ft_strncmp(op, SS, 2) == 0)
	{
		ss(head_a, head_b);
		ft_printf("ss\n");
	}
}
