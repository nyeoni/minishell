/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 18:20:06 by hannkim           #+#    #+#             */
/*   Updated: 2022/07/01 16:29:00 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

/*
	Invalid option -> exit_code = EXIT_FAILURE;
	No such file or directory -> eixt_code = EXIT_FAILURE;
*/
int	ft_cd(char **argv)
{
	t_env	*ptr;
	char	*home;
	int		ret;

	if (!*(argv + 1))
	{
		ptr = get_env("HOME");
		if (!ptr)
			return (throw_error("cd", NULL, strerror(errno)));
		home = ptr->value;
		ret = chdir(home);
		if (ret < 0)
			return (throw_error("cd", NULL, strerror(errno)));
		return (EXIT_SUCCESS);
	}
	if (check_option(*(argv + 1)) == EXIT_FAILURE)
		return (throw_error_usage("cd", *(argv + 1)));
	ret = chdir(*(argv + 1));
	if (ret < 0)
		return (throw_error("cd", *(argv + 1), strerror(errno)));
	return (EXIT_SUCCESS);
}
