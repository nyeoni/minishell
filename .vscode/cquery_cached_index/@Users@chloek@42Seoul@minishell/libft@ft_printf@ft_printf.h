/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 15:26:48 by nkim              #+#    #+#             */
/*   Updated: 2021/09/25 11:38:44 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_putnbr(int n);
int	ft_putunnbr(unsigned int nbr);
int	ft_putunnbr_hex(unsigned long long nbr, char *base);
int	print_c(int arg);
int	print_s(char *arg);
int	print_decimal(int arg);
int	print_un_decimal(unsigned int arg);
int	print_pointer(unsigned long long arg);
int	print_un_hex(unsigned int arg, char type);
int	ft_printf(const char *string, ...);

#endif
