/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student@42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:19:38 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/04/24 14:44:00 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The strdup() function returns a pointer to a new string which is a		*/
/*duplicate of the string s. Memory for the new string is obtained with		*/
/*malloc(3), and can be freed with free(3). On success, returns a pointer to*/
/*the duplicated string.  It returns NULL if insufficient memory was		*/
/*available, with errno set to indicate the cause of the error.				*/

#include "libft.h"

char	*ft_strdup(const char *s)
{
	void	*ptr;
	char	*temp;

	ptr = ft_calloc(ft_strlen(s) + 1, 1);
	if (!ptr)
		return (NULL);
	ft_memcpy (ptr, s, ft_strlen(s) + 1);
	temp = (char *)ptr;
	return (temp);
}
