/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:46:49 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/09/12 15:13:53 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_operation(t_list **head)
{
	if (!head || !(*head) || !(*head)->prev)
		return ;
	*head = (*head)->prev;
}

void	rra(t_list **head_a)
{
	reverse_rotate_operation(head_a);
}

void	rrb(t_list **head_b)
{
	reverse_rotate_operation(head_b);
}

void	rrr(t_list **head_a, t_list **head_b)
{
	rra(head_a);
	rrb(head_b);
}

void	reverse_rotate(char *op, t_list **head_a, t_list **head_b)
{
	if (ft_strncmp(op, "rra", 3) == 0)
	{
		rra(head_a);
		ft_printf("rra\n");
	}
	else if (ft_strncmp(op, "rrb", 3) == 0)
	{
		rrb(head_b);
		ft_printf("rrb\n");
	}
	else if (ft_strncmp(op, "rrr", 3) == 0)
	{
		rrr(head_a, head_b);
		ft_printf("rrr\n");
	}
}
