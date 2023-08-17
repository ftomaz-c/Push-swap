/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student@42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:40:50 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/04/24 14:19:11 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*checks whether the given character is alphanumeric or not.				*/
/*It returns a non-zero value if it is alphanumeric else it returns 0.		*/

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')
		|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}
