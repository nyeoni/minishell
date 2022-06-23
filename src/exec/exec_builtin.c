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

void	exec_builtin(char **argv)
{
	if (!ft_strncmp(*argv, "cd", 3))
		ft_cd(argv);
	else if (!ft_strncmp(*argv, "echo", 5))
		ft_echo(argv);
	else if (!ft_strncmp(*argv, "pwd", 4))
		ft_pwd(argv);
	else if (!ft_strncmp(*argv, "env", 4))
		ft_env();
	else if (!ft_strncmp(*argv, "exit", 5))
		ft_exit();
	else if (!ft_strncmp(*argv, "export", 7))
		ft_export(argv);
	else if (!ft_strncmp(*argv, "unset", 6))
		ft_unset(argv);
}
