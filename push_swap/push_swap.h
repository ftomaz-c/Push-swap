/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 12:18:08 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/09/13 17:42:03 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/includes/libft.h"
# include <limits.h>
# include <stdbool.h>

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
int		stack_size(t_list *head);
void	free_nodes(t_list *a);
void	print_stack(t_list *head, char *label);
int		is_not_organized(t_list *head);
int		is_in_order(t_list *head);

/*operations*/
void	swap(const char *op, t_list **head_a, t_list **head_b);
void	push(char *op, t_list **head_a, t_list **head_b);
void	rotate(char *op, t_list **head_a, t_list **head_b);
void	reverse_rotate(char *op, t_list **head_a, t_list **head_b);

/*small_stack.c*/
void	small_stack(int	size, t_list **head_a, t_list **head_b);

#endif
