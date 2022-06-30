/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_pipe_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 04:57:08 by nkim              #+#    #+#             */
/*   Updated: 2022/06/30 19:25:33 by hannkim          ###   ########.fr       */
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

	init_syntax_pipe_line(ast_pipe_line);
	pipe_line = (*ast_pipe_line)->data;
	token = fetch_token(GET);
	if (!(token.type == T_WORD || token.type == T_REDIRECT))
		return (throw_error_syntax(token));
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
