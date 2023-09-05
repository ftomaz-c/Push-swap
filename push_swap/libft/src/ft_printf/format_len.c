/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:25:35 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/09/05 16:08:16 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	nbr_len(long nbr)
{
	int	len;

	len = 0;
	if (nbr <= 0)
		len++;
	while (nbr != 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

int	ptr_len(unsigned long nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		len += 5;
	while (nbr != 0)
	{
		nbr /= 16;
		len++;
	}
	return (len);
}

int	hex_len(unsigned int nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		len++;
	while (nbr != 0)
	{
		nbr /= 16;
		len++;
	}
	return (len);
}
