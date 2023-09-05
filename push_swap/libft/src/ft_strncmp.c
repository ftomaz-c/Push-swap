/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 17:13:19 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/09/05 16:12:17 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The strncmp() function is similar, except it compares only the first (at	*/
/*most) n bytes of s1 and s2. The strncmp() functions return an				*/
/*integer less than, equal to, or greater than zero if s1 (or the first n	*/
/*bytes thereof) is found, respectively, to be less than, to match, or be	*/
/*greater than s2.															*/

#include "../includes/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && i < n - 1 && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
