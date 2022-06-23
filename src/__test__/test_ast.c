/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:23:17 by nkim              #+#    #+#             */
/*   Updated: 2022/06/23 17:04:22 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_simple_command(t_simple_command *simple_command)
{
	int	ac;

	printf("===simple_command===\n");
	printf("exec_path: %s\n", simple_command->exec_path);
	ac = 0;
	while (simple_command->argv[ac])
	{
		printf("argv[%d]: %s\n", ac, simple_command->argv[ac]);
		ac++;
	}
}

void	print_io_redirect(t_io_redirect *io_redirect)
{
	printf("===io_redirect===\n");
	printf("redirect_op: %s\n", io_redirect->redirect_op);
	printf("argv: %s\n", io_redirect->file_path);
}

void	print_redirects(t_ast *ast)
{
	t_redirects	*redirects;

	if (ast->type == AST_REDIRECTS)
	{
		printf("===redirects===\n");
		redirects = ast->data;
		if (redirects->io_redirect)
			print_io_redirect(redirects->io_redirect);
		if (redirects->redirects)
			print_redirects(redirects->redirects);
	}
}

void	print_command(t_ast *ast)
{
	t_command	*command;

	if (ast->type == AST_COMMAND)
	{
		printf("===command===\n");
		command = ast->data;
		if (command->simple_command)
			print_simple_command(command->simple_command);
		if (command->redirects)
			print_redirects(command->redirects);
	}
}

void	test_ast(t_ast *ast)
{
	t_pipe_line	*pipe_line;

	printf("*****test_ast*****\n");
	if (ast->type == AST_PIPELINE)
	{
		printf("===pipe_line===\n");
		pipe_line = ast->data;
		if (pipe_line->command)
			print_command(pipe_line->command);
		if (pipe_line->pipe_line)
			test_ast(pipe_line->pipe_line);
	}
}
