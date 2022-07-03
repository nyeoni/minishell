/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 18:20:06 by hannkim           #+#    #+#             */
/*   Updated: 2022/07/03 01:56:57 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static int	change_pwd(t_env *pwd)
{
	char	*tmp;

	if (!pwd)
		return (EXIT_FAILURE);
	tmp = pwd->value;
	pwd->value = getcwd(NULL, 0);
	if (!pwd->value)
		return (throw_error_exit("getcwd", strerror(errno), EXIT_FAILURE));
	if (tmp)
		free(tmp);
	return (EXIT_SUCCESS);
}

static int	cd_home(void)
{
	t_env	*ptr;
	char	*home;
	int		exit_code;

	exit_code = change_pwd(get_env("OLDPWD"));
	ptr = get_env("HOME");
	if (!ptr)
		return (throw_error("cd", NULL, strerror(errno)));
	home = ptr->value;
	exit_code = chdir(home);
	if (exit_code < 0)
		return (throw_error("cd", NULL, strerror(errno)));
	exit_code = change_pwd(get_env("PWD"));
	return (EXIT_SUCCESS);
}

/*
	Invalid option -> exit_code = EXIT_FAILURE;
	No such file or directory -> eixt_code = EXIT_FAILURE;
*/
int	ft_cd(char **argv)
{
	int	exit_code;

	exit_code = change_pwd(get_env("OLDPWD"));
	if (!*(argv + 1))
		return (cd_home());
	if (check_option(*(argv + 1)) == EXIT_FAILURE)
		return (throw_error_usage("cd", *(argv + 1)));
	exit_code = chdir(*(argv + 1));
	if (exit_code < 0)
		return (throw_error("cd", *(argv + 1), strerror(errno)));
	exit_code = change_pwd(get_env("PWD"));
	return (exit_code);
}
