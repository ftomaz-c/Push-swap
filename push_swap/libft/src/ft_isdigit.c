/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:11:51 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/09/05 16:10:13 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*checks if the passed character is a digit or not.							*/
/*It returns a non-zero value if it’s a digit else it returns 0.			*/

#include "../includes/libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
