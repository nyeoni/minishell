/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 15:48:31 by nkim              #+#    #+#             */
/*   Updated: 2021/09/25 10:50:38 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_c(int arg)
{
	int		cnt;
	char	c;

	c = (char)arg;
	cnt = write(1, &c, 1);
	return (cnt);
}

int	print_s(char *arg)
{
	int	cnt;

	if (!arg)
		cnt = write(1, "(null)", 6);
	else
		cnt = write(1, arg, ft_strlen(arg));
	return (cnt);
}
