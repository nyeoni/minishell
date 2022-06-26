/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_subshell.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 18:24:53 by nkim              #+#    #+#             */
/*   Updated: 2022/06/26 18:25:10 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// TODO: fork 위에 signal 처리??
pid_t	create_subshell(t_pipe_line *pipe_line)
{
	static int	pipe_fd[2];
	pid_t pid;

	if (pipe(pipe_fd) == -1)
	{
		throw_error("pipe", NULL, strerror(errno));
		return (ERROR_FLAG);
	}
	printf("pipe_rd: %d, pipe_wr: %d\n", pipe_fd[READ], pipe_fd[WRITE]);
	pid = fork();
	if (pid < 0)
		throw_error_exit("fork", strerror(errno), EXIT_FAILURE);
	else if (pid == 0)
	{
		// pipe connect
		close(pipe_fd[READ]);
		if (pipe_line->pipe_line) {
			if (dup2(pipe_fd[WRITE], STDOUT_FILENO) == -1)
				throw_error_exit("dup2", strerror(errno), EXIT_FAILURE);
		}
		close(pipe_fd[WRITE]);
		exec_ast(pipe_line->command);
		exit(g_manager.exit_code);
	}
	close(pipe_fd[WRITE]);
	if (dup2(pipe_fd[READ], STDIN_FILENO) == -1)
		throw_error_exit("dup2", strerror(errno), EXIT_FAILURE);
	close(pipe_fd[READ]);
	return (pid);
}