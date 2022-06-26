/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:40:07 by nkim              #+#    #+#             */
/*   Updated: 2022/06/26 18:25:08 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		exec_io_redirect(t_io_redirect *io_redirect)
{
	printf("exec_io_redirect\n");
	if (io_redirect->redirect_op == R_IN)
		return (redirect_in_file(io_redirect->file_path));
	else if (io_redirect->redirect_op == R_OUT)
		return (redirect_out_file(io_redirect->file_path));
	else if (io_redirect->redirect_op == R_HEREDOC)
		return (redirect_heredoc(io_redirect->file_path));
	else if (io_redirect->redirect_op == R_APPEND)
		return (redirect_append_file(io_redirect->file_path));
	else
		return (ERROR_FLAG);
}

int		exec_redirects(t_redirects *redirects)
{
	int flag;

	flag = SUCCESS_FLAG;
	printf("exec_redirects\n");
	if (redirects->io_redirect)
		flag = exec_io_redirect(redirects->io_redirect);
	if (flag != SUCCESS_FLAG)
		return (ERROR_FLAG);
	if (redirects->redirects)
		flag = exec_ast(redirects->redirects);
	return (flag);
}

int		exec_simple_command(t_simple_command *simple_command)
{
	int exit_code;

	if (is_builtin(simple_command->exec_path))
		exit_code = exec_builtin(simple_command->argv);
	else
		exit_code = exec_general(simple_command->argv);
	g_manager.exit_code = exit_code;
	if (exit_code == EXIT_SUCCESS)
		return (SUCCESS_FLAG);
	else
		return (ERROR_FLAG);
}

// TODO: command->reidrects 가 있을때 heredoc 먼저 처리하는 로직 추가
int		exec_command(t_command *command)
{
	int flag;

	flag = SUCCESS_FLAG;
	// printf("exec_command\n");
	if (command->redirects)
		flag = exec_ast(command->redirects);
	if (flag != SUCCESS_FLAG)
		return (ERROR_FLAG);
	if (command->simple_command)
		flag = exec_simple_command(command->simple_command);
	return (flag);
}

// 2개이상의 pipe 가 있는 명령어 실행하는 함수
int		exec_subshell(t_pipe_line *pipe_line)
{
	pid_t pid;

	pid = create_subshell(pipe_line);
	if (pid == ERROR_FLAG)
		return (ERROR_FLAG);
	if (pipe_line->pipe_line
		&& pipe_line->pipe_line->type == AST_PIPELINE)
		exec_subshell(pipe_line->pipe_line->data);
	else
		wait_subshell(pid);
	return (SUCCESS_FLAG);
}

int		exec_single_command(t_command *command)
{
	pid_t pid;

	if (is_builtin(command->simple_command->exec_path))
		return (exec_command(command));

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

int		exec_pipe_line(t_pipe_line *pipe_line)
{
	if (pipe_line->pipe_line)
		return (exec_subshell(pipe_line));
	else if (pipe_line->command
			&& pipe_line->command->type == AST_COMMAND)
		return (exec_single_command(pipe_line->command->data));
	else
		printf("empty pipeline\n");
	return (ERROR_FLAG);
}

int		exec_ast(t_ast *ast)
{
	if (ast->type == AST_PIPELINE)
		return (exec_pipe_line(ast->data));
	else if (ast->type == AST_COMMAND)
		return (exec_command(ast->data));
	else if (ast->type == AST_REDIRECTS)
		return (exec_redirects(ast->data));
	else
		return (ERROR_FLAG);
}
