/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 20:40:12 by nkim              #+#    #+#             */
/*   Updated: 2022/06/28 21:50:33 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_io_redirect(t_io_redirect *io_redirect)
{
	if (io_redirect->file_path)
		free(io_redirect->file_path);
	free(io_redirect);
}

void	free_simple_command(t_simple_command *simple_command)
{
	int	ac;

	ac = 0;
	while (simple_command->argv[ac])
		free(simple_command->argv[ac++]);
	free(simple_command);
}

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
	else if (ast->type == AST_NULL)
		return ;
}
