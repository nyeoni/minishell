/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 15:21:06 by nkim              #+#    #+#             */
/*   Updated: 2021/09/25 10:51:55 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format(va_list ap, const char *format)
{
	if (*format == 'c')
		return (print_c(va_arg(ap, int)));
	else if (*format == 's')
		return (print_s(va_arg(ap, char *)));
	else if (*format == 'd' || *format == 'i')
		return (print_decimal(va_arg(ap, int)));
	else if (*format == 'u')
		return (print_un_decimal(va_arg(ap, int)));
	else if (*format == 'p')
		return (print_pointer(va_arg(ap, unsigned long long)));
	else if (*format == 'X' || *format == 'x')
		return (print_un_hex(va_arg(ap, unsigned int), *format));
	else if (*format == '%')
		return (write(1, "%", 1));
	else
		return (0);
}

int	manage_print(const char *string, va_list ap)
{
	int	idx;
	int	cnt;

	idx = 0;
	cnt = 0;
	while (string[idx])
	{
		if (string[idx] == '%')
		{
			cnt += print_format(ap, &(string[++idx]));
		}
		else
		{
			write(1, &(string[idx]), 1);
			cnt++;
		}
		idx++;
	}
	return (cnt);
}

int	ft_printf(const char *string, ...)
{
	va_list	ap;
	int		cnt;

	va_start(ap, string);
	cnt = manage_print(string, ap);
	va_end(ap);
	return (cnt);
}
