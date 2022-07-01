/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 04:58:02 by nkim              #+#    #+#             */
/*   Updated: 2022/07/01 16:07:31 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	init_syntax_command(t_ast **ast_command)
{
	*ast_command = bs_calloc(1, sizeof(t_ast));
	(*ast_command)->type = AST_COMMAND;
	(*ast_command)->data = bs_calloc(1, sizeof(t_command));
}

int	syntax_command(t_ast **ast_command)
{
	t_command	*command;
	t_ast		**ast_redirects;
	t_token		token;

	init_syntax_command(ast_command);
	command = (*ast_command)->data;
	ast_redirects = &command->redirects;
	token = fetch_token(GET);
	while (token.type == T_WORD || token.type == T_REDIRECT)
	{
		if (token.type == T_WORD)
		{
			if (syntax_simple_command(&command->simple_command))
				return (ERROR_FLAG);
		}
		else if (token.type == T_REDIRECT)
		{
			if (syntax_redirects(ast_redirects))
				return (ERROR_FLAG);
			ast_redirects = &((t_redirects *)(*ast_redirects)->data)->redirects;
		}
		token = fetch_token(GET);
	}
	return (SUCCESS_FLAG);
}
