/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student@42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 12:54:44 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/04/24 18:25:52 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Allocates (with malloc(3)) and returns a string representing the integer	*/
/* received as an argument. Negative numbers must be handled. Returns the	*/
/* string representing the integer or NULL if the allocation fails.			*/
/*n: the integer to convert.												*/

#include "libft.h"

static int	count_digits(int n)
{
	int	len;

	len = 1;
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		sign;
	int		len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	sign = 0;
	if (n < 0)
	{
		sign = 1;
		n *= -1;
	}
	len = count_digits(n);
	ptr = ft_calloc((len + sign + 1), sizeof(char));
	if (!ptr)
		return (NULL);
	while (len--)
	{
		ptr[len + sign] = n % 10 + '0';
		n /= 10;
	}
	if (sign)
		ptr[0] = '-';
	return (ptr);
}
