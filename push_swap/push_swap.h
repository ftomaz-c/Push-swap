/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 12:18:08 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/11/01 17:18:09 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/includes/libft.h"
# include <limits.h>
# include <stdbool.h>

# define SA "sa"
# define SB "sb"
# define SS "ss"
# define PA "pa"
# define PB "pb"
# define RA "ra"
# define RB "rb"
# define RR "rr"
# define RRA "rra"
# define RRB "rrb"
# define RRR "rrr"
# define DOWNDOWN 1
# define UPUP 2
# define DOWNUP 3
# define UPDOWN 4

typedef struct move_flags
{
	size_t		move_up;
	size_t		move_down;
	size_t		move_tg_up;
	size_t		move_tg_down;
	size_t		moves;
}	t_move_flags;

typedef struct move_costs
{
	size_t				up_cost;
	size_t				up_tg_cost;
	size_t				down_cost;
	size_t				down_tg_cost;
	int					total_cost;
}	t_move_costs;

typedef struct s_list
{
	int					data;
	int					position;
	struct move_costs	move_costs;
	struct move_flags	move_flags;
	struct s_list		*tg;
	struct s_list		*prev;
	struct s_list		*next;
}	t_list;

/*push_swap_utils_1.c*/
void	free_argv(char **argv);
char	*args_to_str(int argc, char **argv);
int		count_args(char **argv);
char	**argv_split(int argc, char **argv);

/*error.c*/
int		has_only_digits(char *arg);
int		error_arg_type(int argc, char **argv);
int		is_within_range(char *arg);
int		has_duplicates(int argc, char **argv);

/*create_stack.c*/
int		create_stack(int argc, char **argv, t_list **head_a);
int		stack_init(t_list **head_a, char **argv, int argc);
int		add_node_to_stack(t_list **head_a, int data);
t_list	*create_node(int data);

/* init_sort.c */
void	init_sort(t_list **head_a, t_list **head_b);
void	small_stack(int size, t_list **head_a, t_list **head_b);
void	big_stack(int size, t_list **head_a, t_list **head_b);

/* small_stack.c */
void	two_element_sort(t_list **head_a, t_list **head_b);
void	three_element_sort(t_list **head_a, t_list **head_b);
void	four_five_element_sort(t_list **head_a, t_list **head_b);

/*operations*/
void	swap(const char *op, t_list **head_a, t_list **head_b);
void	push(char *op, t_list **head_a, t_list **head_b);
void	rotate(char *op, t_list **head_a, t_list **head_b);
void	reverse_rotate(char *op, t_list **head_a, t_list **head_b);

/*push_swap_utils_2.c*/
int		is_in_order(t_list *head);
void	free_nodes(t_list *a);
int		stack_size(t_list *head);
/* void	print_stack(t_list *head, char *label); */

/*push_swap_utils_3.c*/
int		find_min(int size, t_list *head);
int		find_max(t_list *head);
int		get_index(t_list *head, int data);
int		*create_tab(int size, t_list *head);
int		*sort_tab(int size, t_list *head);

/* quick_sort.c */
void	quick_sort(int *arr, int lo, int hi);

/*simple_sort.c*/
void	simple_sort(t_list **head_a, t_list **head_b);

/* complex_sort.c */
t_list	*get_cheapest(t_list **head_b);
void	complex_sort(int size, t_list **head_a, t_list **head_b);
void	complex_partition(int idx, int size, t_list **head_a, t_list **head_b);
void	complex_sort_1(t_list **head_a, t_list **head_b);

/* complex_moves_utils.c */
void	make_moves(t_list *current, t_list **head_a, t_list **head_b);
void	updown(t_list *current, t_list **head_a, t_list **head_b);
void	downup(t_list *current, t_list **head_a, t_list **head_b);
void	downdown(t_list *current, t_list **head_a, t_list **head_b);
void	upup(t_list *current, t_list **head_a, t_list **head_b);

/* complex_push_swap_utils.c */
void	refresh_info(t_list **head_a, t_list **head_b);
void	set_moves(t_list **current);
void	set_costs(t_list **current, t_list *head_a, t_list *head_b);
void	reset_costs(t_list **current);
t_list	*get_target(t_list *head_a, int data);

#endif
