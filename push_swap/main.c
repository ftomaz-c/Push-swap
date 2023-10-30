/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:40:36 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/10/30 18:47:47 by ftomaz-c         ###   ########.fr       */
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

	if (!argv[1])
		return (0);
	argv = argv_split(argc, argv);
	argc = count_args(argv);
	if (error_arg_type(argc, argv))
	{
		free_argv(argv);
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if (argc > 1)
	{
		head_a = NULL;
		head_b = NULL;
		if (create_stack(argc, argv, &head_a))
			init_sort(&head_a, &head_b);
		free_nodes(head_a);
	}
	else
		free_argv(argv);
	return (0);
}

		// ft_printf("\n-------------------------\n");
		// ft_printf("\n");
		// print_stack(head_a, "A");
		// ft_printf("\n");
		// print_stack(head_b, "B");
		// ft_printf("\n");
		// ft_printf("-------------------------\n");
