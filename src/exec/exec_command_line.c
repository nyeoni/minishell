/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 04:50:24 by nkim              #+#    #+#             */
/*   Updated: 2022/06/30 16:13:31 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_redirect_heredoc(t_ast *ast)
{
	int				flag;
	t_redirects		*redirects;
	t_io_redirect	*io_redirect;

	flag = SUCCESS_FLAG;
	redirects = NULL;
	io_redirect = NULL;
	if (ast && ast->type == AST_REDIRECTS)
		redirects = ast->data;
	if (redirects && redirects->io_redirect)
		io_redirect = redirects->io_redirect;
	if (io_redirect->redirect_op == R_HEREDOC)
		flag = redirect_heredoc(io_redirect->end_text, io_redirect->file_path);
	if (redirects->redirects)
		flag &= exec_redirect_heredoc(ast);
	return (flag);
}

int	exec_heredoc(t_ast *ast)
{
	int			flag;
	t_pipe_line	*pipe_line;
	t_command	*command;

	flag = SUCCESS_FLAG;
	pipe_line = NULL;
	command = NULL;
	if (ast && ast->type == AST_PIPELINE)
		pipe_line = ast->data;
	if (pipe_line && pipe_line->command->type == AST_COMMAND)
		command = pipe_line->command->data;
	if (command && command->redirects)
		flag = exec_redirect_heredoc(command->redirects);
	if (pipe_line && pipe_line->pipe_line)
		flag &= exec_heredoc(pipe_line->pipe_line);
	return (flag);
}

int	exec_command_line(t_ast *ast)
{
	if (exec_heredoc(ast))
		return (ERROR_FLAG);
	if (exec_ast(ast))
		return (ERROR_FLAG);
	return (SUCCESS_FLAG);
}
