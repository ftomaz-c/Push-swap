/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 12:18:08 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/09/12 16:56:38 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/includes/libft.h"
# include <limits.h>

typedef struct s_list
{
	int				data;
	struct s_list	*prev;
	struct s_list	*next;
}				t_list;

/*error.c*/
int		error_arg_type(int argc, char **argv);

/*stack_init.c*/
int		stack_init(t_list **head_a, char **argv, int argc);

/*push_swap_utils.c*/
int		size(t_list *head);
void	free_nodes(t_list *a);
int		is_not_organized(t_list *head);
void	print_stack(t_list *head, char *label);

/*swap.c*/
void	swap(const char *op, t_list **head_a, t_list **head_b);

/*push.c*/
void	push(char *op, t_list **head_a, t_list **head_b);

/* rotate.c */
void	rotate(char *op, t_list **head_a, t_list **head_b);

/* reverse_rotate.c */
void	reverse_rotate(char *op, t_list **head_a, t_list **head_b);

void	three_element_sort(t_list **head_a, t_list **head_b);

#endif
