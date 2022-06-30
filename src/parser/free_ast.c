/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 20:40:12 by nkim              #+#    #+#             */
/*   Updated: 2022/06/30 19:26:03 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_redirects(t_redirects *redirects)
{
	if (redirects->io_redirect)
		free_io_redirect(redirects->io_redirect);
	if (redirects->redirects)
		free_ast(redirects->redirects);
	free(redirects);
}

void	free_command(t_command *command)
{
	if (command->simple_command)
		free_simple_command(command->simple_command);
	if (command->redirects)
		free_ast(command->redirects);
	free(command);
}

void	free_pipe_line(t_pipe_line *pipe_line)
{
	if (pipe_line->command)
		free_ast(pipe_line->command);
	if (pipe_line->pipe_line)
		free_ast(pipe_line->pipe_line);
	free(pipe_line);
}

void	free_ast(t_ast *ast)
{
	if (ast->type == AST_PIPELINE)
		free_pipe_line(ast->data);
	else if (ast->type == AST_COMMAND)
		free_command(ast->data);
	else if (ast->type == AST_REDIRECTS)
		free_redirects(ast->data);
	free(ast);
}
