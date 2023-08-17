/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student@42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:07:30 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/04/24 15:01:49 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Allocates and returns a copy of ’s1’ with the characters specified in		*/
/* ’set’ removed from the beginning and the end of the string. Returns the	*/
/* trimmed string or NULL if the allocation fails.							*/
/*s1: The string to be trimmed.												*/
/*set: The reference set of characters to trim.								*/

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char const	*start;
	char const	*end;
	char		*s2;

	if (!s1 || !set)
		return (NULL);
	start = s1;
	while (*start && ft_strchr(set, *start))
		start++;
	end = s1 + ft_strlen(s1) - 1;
	while (end > start && ft_strchr(set, *end))
		end--;
	s2 = ft_substr(start, 0, end - start + 1);
	if (!s2)
		return (NULL);
	return (s2);
}
