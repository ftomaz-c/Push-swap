/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:40:36 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/08/17 21:07:17 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_nodes(t_list *a) {

	t_list	*current;
	t_list	*temp;

	current = a;
	while (current != NULL) {
		temp = current;
		current = current->next;
		free (temp);
	}
}

t_list	*create_node(int data, int index)
{
	t_list	*temp;

	temp = malloc(sizeof(t_list));
	if (!temp)
		return (NULL);
	temp->data = data;
	temp->index = index;
	temp->next = NULL;
	temp->prev = NULL;
	return (temp);
}

void	stack_init(t_list **head_a, t_list **tail_a, char **argv)
{
	t_list	*temp;
	int		index;

	index = 1;
	while (argv[index] != NULL)
	{
		temp = create_node(ft_atoi(argv[index]), index);
		if (!temp)
		{
			free_nodes(*head_a);
			return;
		}
		if (*head_a == NULL)
			*head_a = temp;
		if (*tail_a == NULL)
			*tail_a = temp;
		else
		{
			temp->prev = *tail_a;
			(*tail_a)->next = temp;
			*tail_a = temp;
		}
		index++;
	}
}

/* int	error_arg_type(char **argv) {} */

int	main(int argc, char **argv)
{
	t_list	*head_a;
	t_list	*tail_a;
	t_list	*a;
	// t_list	*head_b;
	// t_list	*tail_b;

	head_a = NULL;
	tail_a = NULL;
	// head_b = NULL;
	// tail_b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return 0;
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	stack_init(&head_a, &tail_a, argv);
	if (argc == 2)
	{
		free_stash(argv, count_words(argv[1], ' '));
		free(argv);
	}
	a = head_a;
	ft_printf("Contents of the linked list:\n");
	while (a != NULL)
	{
		ft_printf("index:	%i, data:	%i\n", a->index, a->data);
		a = a->next;
	}
	ft_printf("\n");
	free_nodes(head_a);
	return 0;
}
