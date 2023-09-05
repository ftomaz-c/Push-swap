/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 18:49:03 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/09/05 16:12:39 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*If c is a  lowercase  letter,  toupper()  returns its uppercase			*/
/*equivalent, if an uppercase representation exists  in the current locale.	*/
/*Otherwise, it returns  c.													*/

#include "../includes/libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= ('a' - 'A');
	return (c);
}
