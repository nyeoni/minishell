/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_pipe_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 04:57:08 by nkim              #+#    #+#             */
/*   Updated: 2022/07/01 01:04:00 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_syntax_pipe_line(t_ast **ast_pipe_line)
{
	*ast_pipe_line = bs_calloc(1, sizeof(t_ast));
	(*ast_pipe_line)->type = AST_PIPELINE;
	(*ast_pipe_line)->data = bs_calloc(1, sizeof(t_pipe_line));
}

int	syntax_pipe_line(t_ast **ast_pipe_line)
{
	t_pipe_line	*pipe_line;
	t_token		token;
	char		*pipe;

	token = fetch_token(GET);
	if (token.type == T_NULL)
		return (SUCCESS_FLAG);
	if (!(token.type == T_WORD || token.type == T_REDIRECT))
		return (throw_error_syntax(token));
	init_syntax_pipe_line(ast_pipe_line);
	pipe_line = (*ast_pipe_line)->data;
	if (syntax_command(&pipe_line->command))
		return (ERROR_FLAG);
	if (fetch_token(GET).type == T_PIPE)
	{
		pipe = match(T_PIPE);
		if (pipe == NULL)
			return (ERROR_FLAG);
		if (syntax_pipe_line(&pipe_line->pipe_line))
			return (ERROR_FLAG);
		free(pipe);
	}
	return (SUCCESS_FLAG);
}
