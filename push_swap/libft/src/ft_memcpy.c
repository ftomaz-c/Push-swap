/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student@42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:08:22 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/04/24 14:34:13 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The memcpy() function copies n bytes from memory area src to memory  area	*/
/* dest. The  memory  areas  must not overlap.  Use memmove(3) if the memory*/
/* areas do overlap. Returns a pointer to dest.								*/

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char	*c_src;
	char		*c_dest;
	size_t		i;

	if (!dest && !src)
		return (NULL);
	c_src = (char *)src;
	c_dest = (char *)dest;
	i = 0;
	while (i < n)
	{
		c_dest[i] = c_src[i];
		i++;
	}
	return (dest);
}
