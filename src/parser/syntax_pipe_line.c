/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_pipe_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 04:57:08 by nkim              #+#    #+#             */
/*   Updated: 2022/06/22 23:21:35 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	syntax_pipe_line(t_ast **ast_pipe_line)
{
	t_pipe_line	*pipe_line;

	*ast_pipe_line = ft_calloc(1, sizeof(t_ast));
	(*ast_pipe_line)->type = AST_PIPELINE;
	(*ast_pipe_line)->data = ft_calloc(1, sizeof(t_pipe_line));
	pipe_line = (*ast_pipe_line)->data;
	syntax_command(&pipe_line->command);
	if (fetch_token(GET).type == T_PIPE)
	{
		match(T_PIPE);
		syntax_pipe_line(&pipe_line->pipe_line);
	}
}
