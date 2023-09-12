/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_element_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:54:06 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/09/12 16:55:41 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_element_sort(t_list **head_a, t_list **head_b)
{
	while (is_not_organized(*head_a))
	{
		if ((*head_a)->data > (*head_a)->next->data)
		{
			if ((*head_a)->next->data < (*head_a)->prev->data)
			{
				if ((*head_a)->data < (*head_a)->prev->data)
					swap("sa", head_a, head_b);
				else
					reverse_rotate("rra", head_a, head_b);
				continue;
			}
			else
				swap("sa", head_a, head_b);
		}
		if ((*head_a)->data < (*head_a)->next->data)
			reverse_rotate("rra", head_a, head_b);
	}
}
