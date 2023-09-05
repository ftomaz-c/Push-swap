/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 19:35:07 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/09/05 16:10:46 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Returns the last node of the list.										*/
/*lst: The beginning of the list.											*/

#include "../includes/libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}
