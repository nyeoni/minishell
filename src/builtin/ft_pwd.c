/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 18:20:37 by hannkim           #+#    #+#             */
/*   Updated: 2022/07/01 16:29:39 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

/*
	Invalid option -> exit_code = EXIT_FAILURE
	Ignore arguments -> exit_code = EXIT_SUCCESS
*/
int	ft_pwd(char **argv)
{
	char	*cwd;

	if (*(argv + 1) && check_option(*(argv + 1)) == EXIT_FAILURE)
		return (throw_error_usage("pwd", *(argv + 1)));
	cwd = getcwd(NULL, 0);
	if (!cwd)
		return (throw_error("pwd", NULL, strerror(errno)));
	ft_putstr_fd(cwd, STDOUT_FILENO);
	ft_putstr_fd("\n", STDOUT_FILENO);
	free(cwd);
	return (EXIT_SUCCESS);
}
