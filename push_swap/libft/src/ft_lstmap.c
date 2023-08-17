/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 12:08:08 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/08/17 17:14:25 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Iterates the list ’lst’ and applies the function ’f’ on the content of	*/
/*each node. Creates a new list resulting of the successive applications of	*/
/*the function ’f’. The ’del’ function is used to delete the content of a	*/
/*node if needed. Returns the new list or NULL if the allocation fails.		*/
/*lst: The address of a pointer to a node.									*/
/*f: The address of the function used to iterate on the list.				*/
/*del: The address of the function used to delete the content of a node if	*/
/*needed.																	*/

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;

	if (!lst || !f)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		new_node = ft_lstnew(f(lst->data));
		if (!new_node)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}
