/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 11:05:28 by hannkim           #+#    #+#             */
/*   Updated: 2022/06/24 03:05:34 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// static char	*find_file(t_args *args, int cmd_index)
// {
// 	char	*filename;
// 	int		i;

// 	i = 0;
// 	while (args->path[i])
// 	{
// 		filename = ft_strjoin(args->path[i], args->cmds[cmd_index][0]);
// 		if (access(filename, X_OK) == 0)
// 			return (filename);
// 		free(filename);
// 		i++;
// 	}
// 	return (args->cmds[cmd_index][0]);
// }

// /*
// static void	cmd_execve(t_args *args, int cmd_index)
// {
// 	char	*filename;

// 	filename = find_file(args, cmd_index);
// 	execve(filename, args->cmds[cmd_index], args->envp);
// 	throw_error();
// //	exit_msg(strerror(errno));
// }
// */
// static void	cmd_execve(t_args *args, int cmd_index)
// {
// 	char	*filename;

// 	filename = find_file(args, cmd_index);
// 	execve(filename, args->cmds[cmd_index], args->envp);
// 	throw_error();
// }

// void	child_process1(t_args *args)
// {
// 	int		infile_fd;

// 	infile_fd = open(args->infile, O_RDONLY);
// 	if (infile_fd < 0)
// 		exit_msg(strerror(errno));
// 	if (dup2(infile_fd, STDIN_FILENO) == -1
// 		|| dup2(args->pipe_fd[WRITE], STDOUT_FILENO) == -1)
// 		exit_msg(strerror(errno));
// 	close(args->pipe_fd[WRITE]);
// 	close(args->pipe_fd[READ]);
// 	close(infile_fd);
// 	cmd_execve(args, 0);
// }

// static void	child_process2(t_args *args)
// {
// 	int		outfile_fd;

// 	outfile_fd = open(args->outfile, O_WRONLY | O_TRUNC | O_CREAT, 0644);
// 	if (outfile_fd < 0)
// 		exit_msg(strerror(errno));
// 	if (dup2(outfile_fd, STDOUT_FILENO) == -1
// 		|| dup2(args->pipe_fd[READ], STDIN_FILENO) == -1)
// 		exit_msg(strerror(errno));
// 	close(args->pipe_fd[READ]);
// 	close(args->pipe_fd[WRITE]);
// 	close(outfile_fd);
// 	cmd_execve(args, 1);
// }

// void	parent_process(t_args *args)
// {
// 	pid_t	pid;
// 	int		statloc;

// 	pid = fork();
// 	if (pid == -1)
// 		exit_msg(strerror(errno));
// 	else if (pid == 0)
// 		child_process2(args);
// 	else
// 	{
// 		close(args->pipe_fd[READ]);
// 		close(args->pipe_fd[WRITE]);
// 		while (wait(&statloc) != -1)
// 			;
// 	}
// }
