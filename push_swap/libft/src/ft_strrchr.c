/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 16:08:53 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/09/05 16:12:24 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The strrchr() function returns a pointer to the last occurrence of the	*/
/* character c in the string s. Return a pointer to the matched character or*/
/* NULL if the character is not found. The terminating null byte is			*/
/* considered part of the string, so that if c is specified as '\0', these	*/
/* functions return a pointer to the terminator.							*/

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	a;
	int				i;

	a = c;
	i = ft_strlen(s);
	if (a == '\0')
		return ((char *)s + i);
	while (i >= 0)
	{
		if (s[i] == a)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}
