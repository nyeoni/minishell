/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:40:07 by nkim              #+#    #+#             */
/*   Updated: 2022/06/24 22:36:37 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_redirects(t_redirects *redirects)
{
	if (redirects->redirects)
		exec_ast(redirects->redirects);
	if (redirects->io_redirect)
		;
}

// TODO: command->reidrects 가 있을때 heredoc 먼저 처리하는 로직 추가
// return exit_code
void	exec_command(t_command *command)
{
	if (command->redirects)
	{
		// heredoc first
		exec_ast(command->redirects);
	}
	if (command->simple_command)
			exit(g_manager.exit_code);
		;
}

void	exec_pipe(t_pipe_line *pipe_line)
// 2개이상의 pipe 가 있는 명령어 실행하는 함수
{
	// 재귀함수 처리

	// while 수만큼 exec_command 하면 되지 않나?


	// 1. pipe_line->command 먼저 처리
	// pipe 생성 pipe_fd 생성
	// pid = fork()
	// if child
	// close pipe_fd[wr]
	// dup2 pipe_fd[wr] -> stdout
	// close pipe_fd[rd]
	// exec_ast(pipe_line->command);
	//
}

void	exec_single_command(t_command *command)
{
	pid_t pid;
	int status;

	if (is_builtin(command->simple_command->exec_path))
	{
		// 여기서는 exit_code global_variable 로 관리
		exec_command(command);
	}
	else
	{
		pid = fork();
		if (pid == 0)
		{
			exec_command(command);
		}
		else
		{
			waitpid(pid, &status, )
		}
		// 여기서는 exit(exit_code);
		// fork
	}
}

void	exec_pipe_line(t_pipe_line *pipe_line)
{
	if (pipe_line->pipe_line)
		exec_pipe(pipe_line);
	else if (pipe_line->command)
		exec_single_command(pipe_line->command->data);
	else
		printf("empty pipeline\n");
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
	else // AST_NULL 인지 확인하기
		printf("no ast type\n");
}
