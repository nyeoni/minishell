/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 04:58:02 by nkim              #+#    #+#             */
/*   Updated: 2022/06/28 17:32:27 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	syntax_command(t_ast **ast_command)
{
	t_command	*command;
	t_ast		**ast_redirects;

	*ast_command = ft_calloc(1, sizeof(t_ast));
	(*ast_command)->type = AST_COMMAND;
	(*ast_command)->data = ft_calloc(1, sizeof(t_command));
	command = (*ast_command)->data;
	ast_redirects = &command->redirects;
	if (!(fetch_token(GET).type == T_WORD
			|| fetch_token(GET).type == T_REDIRECT))
		return (throw_error_syntax(fetch_token(GET)));
	while (fetch_token(GET).type == T_WORD
		|| fetch_token(GET).type == T_REDIRECT)
	{
		if (fetch_token(GET).type == T_WORD)
		{
			if (syntax_simple_command(&command->simple_command))
				return (ERROR_FLAG);
		}
		else if (fetch_token(GET).type == T_REDIRECT)
		{
			if (syntax_redirects(ast_redirects))
				return (ERROR_FLAG);
			ast_redirects = &((t_redirects *)(*ast_redirects)->data)->redirects;
		}
	}
	return (SUCCESS_FLAG);
}
