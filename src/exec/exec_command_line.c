/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:40:07 by nkim              #+#    #+#             */
/*   Updated: 2022/07/01 16:11:06 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	exec_redirects(t_redirects *redirects)
{
	int	flag;

	flag = SUCCESS_FLAG;
	if (redirects->io_redirect)
		flag = exec_io_redirect(redirects->io_redirect);
	if (flag != SUCCESS_FLAG)
		return (ERROR_FLAG);
	if (redirects->redirects)
		flag = exec_ast(redirects->redirects);
	return (flag);
}

int	exec_command(t_command *command)
{
	int	flag;

	flag = SUCCESS_FLAG;
	if (command->redirects)
		flag = exec_ast(command->redirects);
	if (flag != SUCCESS_FLAG)
		return (ERROR_FLAG);
	if (command->simple_command)
		flag = exec_simple_command(command->simple_command);
	return (flag);
}

int	exec_pipe_line(t_pipe_line *pipe_line)
{
	int	flag;

	flag = SUCCESS_FLAG;
	if (pipe_line->pipe_line)
		flag = exec_subshell(pipe_line);
	else if (pipe_line->command && pipe_line->command->type == AST_COMMAND)
		flag = exec_single_command(pipe_line->command->data);
	else
		flag = ERROR_FLAG;
	return (flag);
}

int	exec_ast(t_ast *ast)
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

int	exec_command_line(t_ast **ast)
{
	if (exec_heredoc(ast))
		return (ERROR_FLAG);
	if (exec_ast(*ast))
		return (ERROR_FLAG);
	return (SUCCESS_FLAG);
}
