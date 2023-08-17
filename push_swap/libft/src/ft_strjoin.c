/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student@42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:38:34 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/04/24 14:45:38 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Allocates (with malloc(3)) and returns a new string, which is the result	*/
/*of the concatenation of ’s1’ and ’s2’. Returns the new string or NULL if	*/
/*the allocation fails.														*/
/*s1: The prefix string.													*/
/*s2: The suffix string.													*/

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_s;
	int		s1_len;
	int		s2_len;
	int		new_s_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_s_len = s1_len + s2_len + 1;
	new_s = ft_calloc(sizeof(char), new_s_len);
	if (!new_s)
		return (NULL);
	ft_strlcpy(new_s, s1, s1_len + 1);
	ft_strlcat(new_s, s2, new_s_len);
	return (new_s);
}
