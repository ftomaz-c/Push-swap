/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:40:36 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/08/19 18:03:24 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	counts_nodes(t_list *head)
{
	int		count;
	t_list	*current;

	current = head->next;
	count = 0;
	while (current != NULL)
	{
		count++;
		current = current->next;
		if (current->next == head)
			break ;
	}
	return (count);
}

int	main(int argc, char **argv)
{
	t_list	*head_a;
	t_list	*head_b;

	if (error_arg_type(argc, argv))
		return (ft_printf("Error\n"));
	if (argc > 2)
	{
		head_a = NULL;
		head_b = NULL;

		stack_init(&head_a, argv, argc);

		ft_printf("\nList A:\n");
		t_list *current_a = head_a;
		int	i = counts_nodes(head_a);
		while (i >= 0)
		{
			ft_printf("index: %i, data: %i\n", current_a->index, current_a->data);
			current_a = current_a->next;
			i--;
		}

		ft_printf("\n");
		pb(&head_a, &head_b);
		i = counts_nodes(head_b);
		ft_printf("%i\n", i);
		ft_printf("\nList B:\n");
		t_list *current_b = head_b;
		while (i >= 0)
		{
			ft_printf("index: %i, data: %i\n", current_b->index, current_b->data);
			i--;
		}

		ft_printf("\n");

		free_nodes(head_a);
	}
	return (0);
}

/* 		t_list	*a = head_a;
		int		i = 0;
		ft_printf("Contents of the linked list:\n");
		while (i < argc + 3)
		{
			ft_printf("index:	%i, data:	%i\n", a->index, a->data);
			a = a->next;
			i++;
		}
		ft_printf("\n"); */
