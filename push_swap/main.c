/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:40:36 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/09/07 17:44:16 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stack(t_list *head, char *label)
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
		if (stack_init(&head_a, argv, argc))
			return(ft_printf("Error\n"));

		print_stack(head_a, "A");
		print_stack(head_b, "B");

		ft_printf("\n");

		push("pb", &head_a, &head_b);
		print_stack(head_a, "A");
		print_stack(head_b, "B");

		ft_printf("\n");

		push("pb", &head_a, &head_b);
		print_stack(head_a, "A");
		print_stack(head_b, "B");

		ft_printf("\n");

		push("pb", &head_a, &head_b);
		print_stack(head_a, "A");
		print_stack(head_b, "B");

		ft_printf("\n");

		swap("sa", &head_a, &head_b);
		print_stack(head_a, "A");
		print_stack(head_b, "B");

		ft_printf("\n");

		swap("sb", &head_a, &head_b);
		print_stack(head_a, "A");
		print_stack(head_b, "B");

		ft_printf("\n");

		rotate("ra", &head_a, &head_b);
		print_stack(head_a, "A");
		print_stack(head_b, "B");

		ft_printf("\n");

		rotate("rb", &head_a, &head_b);
		print_stack(head_a, "A");
		print_stack(head_b, "B");

		ft_printf("\n");

		rotate("rr", &head_a, &head_b);
		print_stack(head_a, "A");
		print_stack(head_b, "B");

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
