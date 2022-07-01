/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 23:58:57 by hannkim           #+#    #+#             */
/*   Updated: 2022/07/01 16:29:44 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

/*
	Invalid env_name -> exit_code = EXIT_FAILURE
	Invalid option -> exit_code = 2
*/
int	ft_unset(char **argv)
{
	t_env	*target;
	int		exit_code;

	exit_code = EXIT_SUCCESS;
	if (!*(argv + 1))
		return (exit_code);
	argv++;
	while (*argv)
	{
		if (check_option(*argv) == EXIT_FAILURE)
			exit_code = throw_error_usage("unset", *argv) + 1;
		else if (ft_strchr(*argv, '='))
			exit_code = throw_error_env("unset", *argv);
		else if (valid_env_name(*argv) == EXIT_FAILURE)
			exit_code = throw_error_env("unset", *argv);
		else
		{
			target = get_env(*argv);
			if (target)
				remove_env(target);
		}
		argv++;
	}
	return (exit_code);
}
