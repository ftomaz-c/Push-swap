/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student@42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:38:54 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/04/24 17:18:40 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*checks if the passed character is an alphabet or not.						*/
/*It returns a non-zero value if it’s an alphabet else it returns 0.		*/

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}
