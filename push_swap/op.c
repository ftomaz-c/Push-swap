/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 12:28:17 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/08/17 13:27:35 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//operations:

//sa or sb (swap a or b): swap the first 2 elements of stack a or b.
//Do nothing if there is only one or no elements;

// ss: sa and sb at the same time;

// pa or pb: (push a or b): take the first element at the top of b and put it at the top of a, or vice versa.
//Do nothing if b is empty;

// ra or rb: (rotate a or b): Shift up all elements of the stack by 1.
//The first element becomes the last one;

// rr: ra and rb at the same time;

// rra or rrb: (reverse rotate a or b): Shift down all elements of the stack by 1.
//The last element becomes the first one;

// rrr: rra and rrb at the same time.
