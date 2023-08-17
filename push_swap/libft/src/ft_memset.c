/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student@42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:19:56 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/04/24 14:37:41 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The memset() function fills the first n bytes of the memory area pointed	*/
/* to by s with the constant byte c. Returns a pointer to the memory area s.*/
/*void *s  - It's the pointer of the memory location where the memory will	*/
/* be set;																	*/
/*int c    - It's the value that is to be copied to the memory block;		*/
/*size_t n - It's the number of bytes in the memory block which is set;		*/

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = c;
		i++;
	}
	return (s);
}
