/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 18:20:26 by hannkim           #+#    #+#             */
/*   Updated: 2022/07/01 17:10:46 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static int	check_lld(unsigned long long res, int sign)
{
	if (res > 9223372036854775807UL && sign > 0)
		return (FALSE);
	if (res > 9223372036854775808UL && sign < 0)
		return (FALSE);
	return (TRUE);
}

/*
	invalid exit_code (out of range long long) => return (FALSE);
	valid exit_code => return (TRUE);
*/
static int	valid_exit_code(const char *s)
{
	char				*ptr;
	unsigned long long	res;
	int					sign;
	int					count;

	ptr = (char *)s;
	res = 0;
	count = 0;
	sign = 1;
	if (*ptr == '-')
	{
		sign = -1;
		ptr++;
	}
	while (*ptr && count < 19)
	{
		res = res * 10 + (*ptr - '0');
		ptr++;
		count++;
	}
	return (check_lld(res, sign));
}

/*
	<exit_code>
	string => 255 ("numeric argument required")
	0~255 => 0~255
	out of range 0~255 => overflow operation
	long long MAX => 255
	long long MIN => 0
	out of range long long => 255 ("numeric argument required")
*/
static unsigned char	check_exit_arg(char *arg)
{
	unsigned char	exit_code;
	char			*ptr;

	ptr = arg;
	if (*ptr == '-')
		ptr++;
	while (*ptr)
	{
		if (!ft_isdigit(*ptr))
		{
			exit_code = 255;
			return (exit_code);
		}
		ptr++;
	}
	if (valid_exit_code(arg) != 1)
		exit_code = 255;
	else
		exit_code = ft_atoi(arg);
	return (exit_code);
}

int	ft_exit(char **argv)
{
	unsigned char	exit_code;

	exit_code = EXIT_SUCCESS;
	ft_putstr_fd("exit\n", STDOUT_FILENO);
	if (*(argv + 1))
	{
		exit_code = check_exit_arg(*(argv + 1));
		if (*(argv + 2))
		{
			ft_putendl_fd("blackhole-shell: exit: too many arguments",
				STDERR_FILENO);
			return (EXIT_FAILURE);
		}
	}
	free_env();
	exit(exit_code);
	return (EXIT_FAILURE);
}
