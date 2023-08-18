/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 12:28:17 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/08/18 19:27:52 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//sa or sb (swap a or b): swap the first 2 elements of stack a or b.
// Do nothing if there is only one or no elements;
//sa or sb (swap a or b): swap the first 2 elements of stack a or b.
// Do nothing if there is only one or no elements;
//ss: sa and sb at the same time;

void	sa(t_list **head_a)
{
	int		tmp;
	t_list	*current;

	current = (*head_a)->next;
	tmp = current->data;
	current->data = (*head_a)->data;
	(*head_a)->data = tmp;
}

void	sb(t_list **head_b)
{
	int		tmp;
	t_list	*current;

	current = (*head_b)->next;
	tmp = current->data;
	current->data = (*head_b)->data;
	(*head_b)->data = tmp;
}

void	ss(t_list **head_a, t_list **head_b)
{
	if (!*head_a || !*head_b)
		return ;
	sa(head_a);
	sb(head_b);
}

void	swap(const char *str, ...)
{
	va_list	args;

	va_start(args, str);
	if (str[0] == 's' && str[1] == 'a')
	{
		sa(va_arg(args, t_list **));
		ft_printf("sa\n");
	}
	else if (str[0] == 's' && str[1] == 'b')
	{
		sb(va_arg(args, t_list **));
		ft_printf("sb\n");
	}
	else if (str[0] == 's' && str[1] == 's')
	{
		ss(va_arg(args, t_list **), va_arg(args, t_list **));
		ft_printf("ss\n");
	}
	va_end(args);
}
