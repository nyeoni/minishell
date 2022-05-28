/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 16:39:33 by nkim              #+#    #+#             */
/*   Updated: 2021/09/25 10:50:21 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_decimal(int arg)
{
	int	cnt;

	cnt = ft_putnbr(arg);
	return (cnt);
}

int	print_un_decimal(unsigned int arg)
{
	int	cnt;
	int	un;

	un = arg;
	cnt = ft_putunnbr(un);
	return (cnt);
}

int	print_un_hex(unsigned int arg, char type)
{
	int			cnt;
	signed int	un;
	char		*base;

	un = arg;
	if (type == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	cnt = ft_putunnbr_hex(arg, base);
	return (cnt);
}

int	print_pointer(unsigned long long arg)
{
	int		cnt;
	char	*base;

	base = "0123456789abcdef";
	write(1, "0x", 2);
	cnt = ft_putunnbr_hex(arg, base);
	return (cnt + 2);
}
