/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 12:18:08 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/09/07 15:38:42 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/includes/libft.h"
# include <limits.h>

typedef struct s_list
{
	int				data;
	int				index;
	struct s_list	*prev;
	struct s_list	*next;
}				t_list;

/*error.c*/
int		error_arg_type(int argc, char **argv);

/*stack_init.c*/
int		stack_init(t_list **head_a, char **argv, int argc);

/*push_swap_utils.c*/
int		counts_nodes(t_list *head)
void	free_nodes(t_list *a);

/*swap.c*/
void	swap(const char *op, t_list **head_a, t_list **head_b);

#endif
