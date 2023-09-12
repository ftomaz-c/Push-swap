/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:40:36 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/09/12 16:57:01 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

		ft_printf("-> moves <-\n");
		if (argc == 4)
			three_element_sort(&head_a, &head_b);
		ft_printf("\n");

		print_stack(head_a, "A");
		print_stack(head_b, "B");
		ft_printf("\n");

		free_nodes(head_a);
	}
	return (0);
}
