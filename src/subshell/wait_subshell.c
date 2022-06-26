/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_subshell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 21:44:51 by nkim              #+#    #+#             */
/*   Updated: 2022/06/26 21:09:33 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_exit_code(int status)
{
	if (WIFEXITED(status))
		g_manager.exit_code = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
	{
		g_manager.exit_code = 128 + WTERMSIG(status);
		if (g_manager.exit_code == 131)
			ft_putendl_fd("Quit: 3", STDERR_FILENO);
	}
	else
		g_manager.exit_code = EXIT_FAILURE;
}

void	wait_subshell(pid_t last_pid)
{
	pid_t	pid;
	int		status;

	pid = 0;
	while (pid != ERROR_FLAG)
	{
		pid = waitpid(-1, &status, WUNTRACED);
		if (pid == last_pid)
			set_exit_code(status);
	}
}
