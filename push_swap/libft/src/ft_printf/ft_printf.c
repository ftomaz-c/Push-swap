/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:02:19 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/08/17 12:12:43 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putchari_fd(char c, int fd)
{
	return (write (fd, &c, 1));
}

int	ft_parse(const char *format, va_list args)
{
	if (*format == 'c')
		return (ft_putchari_fd(va_arg(args, int), 1));
	if (*format == 's')
		return (str_format(va_arg(args, char *)));
	if (*format == 'p')
		return (ptr_format(va_arg(args, void *)));
	if (*format == 'd' || *format == 'i')
		return (nbr_format(va_arg(args, int)));
	if (*format == 'u')
		return (unsg_format(va_arg(args, unsigned int)));
	if (*format == 'x' || *format == 'X')
		return (hex_format(va_arg(args, int), format));
	if (*format == '%')
		return (ft_putchari_fd('%', 1));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int			count;
	va_list		args;

	if (!format)
		return (0);
	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
			count += ft_parse(++format, args);
		else if (*format != '%')
			count += ft_putchari_fd(*format, 1);
		format++;
	}
	va_end(args);
	return (count);
}
