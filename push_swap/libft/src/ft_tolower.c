/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student@42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 18:58:38 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/04/24 15:03:27 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*If   c   is   an  uppercase  letter, tolower()  returns   its   lowercase	*/
/*equivalent, if a lowercase representation exists in the current locale.	*/
/*Otherwise, it returns c.													*/

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += ('a' - 'A');
	return (c);
}
