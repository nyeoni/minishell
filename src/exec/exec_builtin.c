/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 03:38:25 by nkim              #+#    #+#             */
/*   Updated: 2022/06/24 03:38:39 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_builtin(char **argv)
{
	if (!ft_strncmp(*argv, "echo", 5))
		return (ft_echo(argv));
	if (!ft_strncmp(*argv, "cd", 3))
		return (ft_cd(argv));
	else if (!ft_strncmp(*argv, "pwd", 4))
		return (ft_pwd(argv));
	else if (!ft_strncmp(*argv, "env", 4))
		return (ft_env());
	else if (!ft_strncmp(*argv, "export", 7))
		return (ft_export(argv));
	else if (!ft_strncmp(*argv, "unset", 6))
		return (ft_unset(argv));
	else if (!ft_strncmp(*argv, "exit", 5))
		ft_exit();
	return (EXIT_FAILURE);
}
