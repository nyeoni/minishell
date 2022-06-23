/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:40:07 by nkim              #+#    #+#             */
/*   Updated: 2022/06/23 17:08:51 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_redirects(t_redirects *redirects)
{
	if (redirects->io_redirect)
		if (redirects->redirects)
			exec_ast(redirects->redirects);
}

void	exec_command(t_command *command)
{
	if (command->simple_command)
		if (command->redirects)
			exec_ast(command->redirects);
}

void	exec_pipe_line(t_pipe_line *pipe_line)
{
	if (pipe_line->pipe_line)
	{
	}
	else if (pipe_line->command)
		exec_ast(pipe_line->command);
}

/*
	void	exec_ast(t_ast *ast)
{
	if (ast->type == AST_PIPELINE)
		exec_pipe_line(ast->data);
	else if (ast->type == AST_COMMAND)
		exec_command(ast->data);
	else if (ast->type == AST_REDIRECTS)
		exec_redirects(ast->data);
	else
		return ; // 여기에 NULL인게 처리됨
}
*/
void	exec_ast(t_ast *ast)
{
	if (ast->type == AST_PIPELINE)
		exec_pipe_line(ast->data);
	else if (ast->type == AST_COMMAND)
		exec_command(ast->data);
	else if (ast->type == AST_REDIRECTS)
		exec_redirects(ast->data);
	else
		return ;
}
