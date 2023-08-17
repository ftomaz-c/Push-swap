/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student@42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:34:36 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/04/24 14:36:48 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The  memmove()  function  copies  n  bytes  from memory area src to		*/
/*memory area dest.  The memory areas may overlap: copying takes place as	*/
/*though the bytes in src are first copied into a temporary array that does	*/
/*not overlap src or dest, and the bytes are then copied  from  the			*/
/*temporary array to dest. Returns a pointer to dest.						*/

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*memsrc;
	char		*memdest;

	memsrc = (const char *)src;
	memdest = (char *)dest;
	if (dest > src)
	{
		while (n--)
			memdest[n] = memsrc[n];
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
