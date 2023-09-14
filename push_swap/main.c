/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:40:36 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/09/14 10:55:55 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// With 3 numbers, we need to sort it with not more than 3 instructions.

// With 5 numbers, we need to sort it with not more than 12 instructions.

// With 100 numbers:
// 	5 points if the size of the list of instructions is less than 700
// 	4 points if the size of the list of instructions is less than 900
// 	3 points if the size of the list of instructions is less than 1100
// 	2 points if the size of the list of instructions is less than 1300
// 	1 points if the size of the list of instructions is less than 1500

// With 500 numbers:
// 	5 points if the size of the list of instructions is less than 5500
// 	4 points if the size of the list of instructions is less than 7000
// 	3 points if the size of the list of instructions is less than 8500
// 	2 points if the size of the list of instructions is less than 10000
// 	1 points if the size of the list of instructions is less than 11500

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*head_a;
	t_list	*head_b;
	int		size;

	if (error_arg_type(argc, argv))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if (argc > 2)
	{
		head_a = NULL;
		head_b = NULL;
		if (stack_init(&head_a, argv, argc))
		{
			ft_putstr_fd("Error\n", 2);
			return(0);
		}

		// print_stack(head_a, "A");
		// print_stack(head_b, "B");
		// ft_printf("\n");

		// ft_printf("-> moves <-\n");
		size = stack_size(head_a);
		if (size <= 5)
			small_stack(size, &head_a, &head_b);
		// if (size > 5)
		// 	big_stack(&head_a, &head_b);
		// ft_printf("\n");

		// print_stack(head_a, "A");
		// print_stack(head_b, "B");
		// ft_printf("\n");

		free_nodes(head_a);
	}
	return (0);
}
