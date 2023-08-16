/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:40:36 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/08/16 16:18:46 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "push_swap.h"

// argv, can be passed as 2 arguments with the use of "";
// stack init
// swap
// 	push swap

void	free_nodes(stack_node **stack, int index) {}

void	stack_init(stack_node **a, t_list **new_argv) {

	int		nbr;
	int		index;
	t_list	*current;

	index = 0;
	current = *new_argv;
	while(current) {
		nbr = ft_atoi(current->content);
		a[index] = malloc(sizeof(stack_node));
		if (!a[index]) {
			free_nodes(a, index);
			return;
		}
		a[index]->data = malloc(sizeof(int));
		if (!a[index]->data) {
			free_nodes(a, index);
			return;
		}
		a[index]->data = nbr;
		a[index]->index = index;
		a[index]->next = NULL;
		if (index == 0)
			a[index]->prev = NULL;
		else
			a[index]->prev = a[index - 1];
		index++;
		current = current->next;
	}
}

int	error_arg_type(t_list **argv) {}

int	main(int argc, char **argv)
{
	stack_node	*a;
	stack_node	*b;
	t_list		**new_argv;

	a = NULL;
	b = NULL;
	if(argc == 1 || (argc == 2 && !argv[1][0]))
		return 0;
	else if (argc == 2)
		new_argv = ft_split(argv[1], ' ');
	if (!error_arg_type(new_argv)) //error handling for the arguments
		stack_init(&a, new_argv);
	else
		return(ft_printf("Error\n"));
}
