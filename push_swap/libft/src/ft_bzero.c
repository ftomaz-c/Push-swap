/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:13:26 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/09/05 16:09:56 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The bzero() function erases the data in the n bytes of the memory starting*/
/* at the location pointed to by s, by writing zeros (bytes containing '\0')*/
/* to that area.				 											*/
/*void *s  - It's the pointer of the memory location where the memory will  */
/* be set;																	*/
/*size_t n - It's the number of bytes in the memory block which is set;	    */

#include "../includes/libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
