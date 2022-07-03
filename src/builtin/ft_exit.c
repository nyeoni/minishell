/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 18:20:26 by hannkim           #+#    #+#             */
/*   Updated: 2022/07/03 16:22:10 by hannkim          ###   ########.fr       */
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

	ptr = (char *)s;
	res = 0;
	sign = 1;
	if (*ptr == '-')
	{
		sign = -1;
		ptr++;
	}
	while (*ptr)
	{
		if (res > res * 10 + (*ptr - '0'))
			return (FALSE);
		res = res * 10 + (*ptr - '0');
		ptr++;
	}
	return (check_lld(res, sign));
}

/*
	<exit_code>
	string => EXIT_MAX ("numeric argument required")
	0~EXIT_MAX => 0~255
	out of range 0~EXIT_MAX => overflow operation
	long long MAX => EXIT_MAX
	long long MIN => 0
	out of range long long => EXIT_MAX ("numeric argument required")
*/
static unsigned char	check_exit_arg(char *arg)
{
	char			*ptr;

	ptr = arg;
	if (*ptr == '-')
		ptr++;
	while (*ptr)
	{
		if (!ft_isdigit(*ptr))
		{
			throw_error("exit", ptr, "numeric argument required");
			exit(EXIT_MAX);
		}
		ptr++;
	}
	if (valid_exit_code(arg) == FALSE)
	{
		throw_error("exit", ptr, "numeric argument required");
		exit(EXIT_MAX);
	}
	return (ft_atoi(arg));
}

int	ft_exit(char **argv)
{
	unsigned char	exit_code;

	exit_code = EXIT_SUCCESS;
	ft_putstr_fd("exit\n", STDERR_FILENO);
	if (*(argv + 1))
	{
		exit_code = check_exit_arg(*(argv + 1));
		if (*(argv + 2))
			return (throw_error("exit", NULL, "too many arguments"));
	}
	free_env();
	exit(exit_code);
	return (EXIT_FAILURE);
}
