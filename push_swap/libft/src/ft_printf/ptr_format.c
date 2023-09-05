/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 20:16:26 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/09/05 16:09:08 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ptr_format(void *ptr)
{
	unsigned long	adr;
	int				len;

	adr = (unsigned long)ptr;
	len = ptr_len(adr);
	if (adr == 0)
		ft_putstr_fd("(nil)", 1);
	else
	{
		ft_putstr_fd("0x", 1);
		ft_putnbr_base_fd(adr, "0123456789abcdef", 1);
		len += 2;
	}
	return (len);
}
