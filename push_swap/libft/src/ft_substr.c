/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:16:54 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/09/05 16:12:32 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Allocates (with malloc(3)) and returns a substring from the string ’s’.	*/
/*The substring begins at index ’start’ and is of maximum size ’len’.		*/
/*Returns the substring or NULL if the allocation fails.					*/
/*s: The string from which to create the substring.							*/
/*start: The start index of the substring in the string ’s’.				*/
/*len: The maximum length of the substring.									*/

#include "../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ss;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (!s || !len || start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	ss = ft_calloc(sizeof(char), len + 1);
	if (!ss)
		return (NULL);
	ft_strlcpy(ss, s + start, len + 1);
	return (ss);
}
