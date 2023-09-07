/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:46:49 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/09/07 17:04:07 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_operation(t_list **head)
{
	if (!head || !(*head) || !(*head)->prev)
		return ;
	*head = (*head)->prev;
}

void	ra(t_list **head_a)
{
	rotate_operation(head_a);
}

void	rb(t_list **head_b)
{
	rotate_operation(head_b);
}

void	rr(t_list **head_a, t_list **head_b)
{
	ra(head_a);
	rb(head_b);
}

void	rotate(char *op, t_list **head_a, t_list **head_b)
{
	if (ft_strncmp(op, "ra", 2) == 0)
	{
		ra(head_a);
		ft_printf("ra\n");
	}
	else if (ft_strncmp(op, "rb", 2) == 0)
	{
		rb(head_b);
		ft_printf("rb\n");
	}
	else if (ft_strncmp(op, "rr", 2) == 0)
	{
		rr(head_a, head_b);
		ft_printf("rr\n");
	}
}
