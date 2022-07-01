/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_single_command.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 21:18:52 by nkim              #+#    #+#             */
/*   Updated: 2022/07/01 15:07:56 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_single_command(t_command *command)
{
	pid_t	pid;

	if (command->simple_command
		&& is_builtin(command->simple_command->exec_path))
		return (exec_command(command));
	if (!bs_strcmp(*command->simple_command->argv, "./minishell"))
	{
		write(1, "!!!", 4);
		multishell_signal();
	}
	else
		change_signal();
	pid = fork();
	if (pid < 0)
		throw_error_exit("fork", strerror(errno), EXIT_FAILURE);
	else if (pid == 0)
	{
		exec_command(command);
		exit(g_manager.exit_code);
	}
	else
	{
		wait_subshell(pid);
	}
	return (SUCCESS_FLAG);
}
