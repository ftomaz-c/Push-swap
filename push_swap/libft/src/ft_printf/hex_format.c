/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:47:44 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/09/05 16:08:55 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	hex_format(unsigned int hex, const char *format)
{
	int	len;

	len = hex_len(hex);
	if (*format == 'x')
		ft_putnbr_base_fd(hex, "0123456789abcdef", 1);
	else if (*format == 'X')
		ft_putnbr_base_fd(hex, "0123456789ABCDEF", 1);
	return (len);
}
