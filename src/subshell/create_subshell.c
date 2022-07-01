/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_subshell.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 18:24:53 by nkim              #+#    #+#             */
/*   Updated: 2022/07/01 16:15:06 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "bs_signal.h"

void	close_pipe_fd(int pipe_fd[2])
{
	if (close(pipe_fd[0]) == -1)
		throw_error_exit("close", strerror(errno), EXIT_FAILURE);
	if (close(pipe_fd[1]) == -1)
		throw_error_exit("close", strerror(errno), EXIT_FAILURE);
}

void	connect_pipe(int pipe_fd[2], int pipe_type)
{
	if (dup2(pipe_fd[pipe_type], pipe_type) == -1)
		throw_error_exit("dup2", strerror(errno), EXIT_FAILURE);
	close_pipe_fd(pipe_fd);
}

// printf("pipe_rd: %d, pipe_wr: %d\n", pipe_fd[READ], pipe_fd[WRITE]);
pid_t	create_subshell(t_pipe_line *pipe_line)
{
	static int	pipe_fd[2];
	pid_t		pid;

	if (pipe(pipe_fd) == -1)
	{
		throw_error("pipe", NULL, strerror(errno));
		return (ERROR_FLAG);
	}
	change_signal();
	pid = fork();
	if (pid < 0)
		throw_error_exit("fork", strerror(errno), EXIT_FAILURE);
	else if (pid == 0)
	{
		if (pipe_line->pipe_line)
			connect_pipe(pipe_fd, WRITE);
		else
			close_pipe_fd(pipe_fd);
		exec_ast(pipe_line->command);
		exit(g_manager.exit_code);
	}
	connect_pipe(pipe_fd, READ);
	return (pid);
}
