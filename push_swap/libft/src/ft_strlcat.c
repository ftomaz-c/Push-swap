/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 18:17:29 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/09/05 16:12:01 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The strlcat() function appends the NUL-terminated string src to the end of*/
/*dst. It will append at most size - strlen(dst) - 1 bytes, NUL-terminating	*/
/*the result.																*/

#include "../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	src_len;
	unsigned int	dst_len;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	i = 0;
	j = dst_len;
	if (size == 0 || size <= dst_len)
		return (src_len + size);
	while (src[i] && (i < size - dst_len - 1))
	{
		dst[j++] = src[i++];
	}
	dst[j] = '\0';
	return (src_len + dst_len);
}
