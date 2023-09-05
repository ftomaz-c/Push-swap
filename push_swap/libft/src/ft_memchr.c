/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 18:24:41 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/09/05 16:11:00 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The memchr() function scans the initial n bytes of the memory area		*/
/* pointed to by s for the first instance of c. Both c and the bytes of the	*/
/* memory area pointed to by s are interpreted as unsigned char. Returns a	*/
/* pointer to the matching byte or NULL if the  character does not occur in	*/
/* the given memory area.													*/

#include "../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((const unsigned char *)s)[i] == (unsigned char)c)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}
