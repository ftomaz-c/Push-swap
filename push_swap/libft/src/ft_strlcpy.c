/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:31:11 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/09/05 16:12:06 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*strlcpy() is used to copy a string from the source string to the			*/
/*destination string, while ensuring that the destination string is null	*/
/*terminated and does not exceed a specified size.							*/

#include "../includes/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size != 0)
	{
		while (i < size - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i] != '\0')
		i++;
	return (i);
}
