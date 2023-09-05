/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 08:39:39 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/09/05 16:11:03 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The memcmp() function compares the first n bytes (each interpreted as		*/
/*unsigned char) of the memory areas s1 and s2. Returns an integer less		*/
/*than, equal to, or greater than zero if the first n bytes of s1 is found,	*/
/*respectively, to be less than, to match, or be greater than the first n	*/
/*bytes of s2. For a nonzero return value, the sign is determined by the	*/
/*sign of the difference between the first pair of bytes (interpreted as	*/
/*unsigned char) that differ in s1 and s2. If n is zero, the return value	*/
/*is zero.																	*/

#include "../includes/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*c_s1;
	const unsigned char	*c_s2;

	if (n == 0)
		return (0);
	c_s1 = s1;
	c_s2 = s2;
	i = 0;
	while (i < n - 1 && c_s1[i] == c_s2[i])
		i++;
	return (c_s1[i] - c_s2[i]);
}
