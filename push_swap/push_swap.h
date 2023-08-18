/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 12:18:08 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/08/18 19:42:59 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/src/libft.h"
# include <limits.h>

typedef struct s_list
{
	int				data;
	int				index;
	struct s_list	*prev;
	struct s_list	*next;
}				t_list;

int		error_arg_type(int argc, char **argv);
void	stack_init(t_list **head_a, char **argv, int argc);
t_list	*create_node(int data, int index);
void	free_nodes(t_list *a);

void	swap(const char *str, ...);
void	sa(t_list **head_a);
void	sb(t_list **head_b);
void	ss(t_list **head_a, t_list **head_b);

void	pb(t_list **head_a, t_list **head_b);

#endif
