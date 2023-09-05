/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 19:59:04 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/09/05 16:10:40 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Takes as a parameter a node and frees the memory of the node’s content	*/
/*using the function ’del’ given as a parameter and free the node. The		*/
/*memory of ’next’ must not be freed.										*/
/*lst: The node to free.													*/
/*del: The address of the function used to delete the content.				*/

#include "../includes/libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free (lst);
}
