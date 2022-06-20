/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 04:58:02 by nkim              #+#    #+#             */
/*   Updated: 2022/06/20 17:32:00 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// TODO: else 다음에 Syntax error 처리하기
void	syntax_command(t_ast *ast_command)
{
	t_command	*command;

	printf("===command===\n");
	ast_command = ft_calloc(1, sizeof(t_ast));
	ast_command->type = AST_COMMAND;
	ast_command->data = ft_calloc(1, sizeof(t_command));
	command = ast_command->data;
	if (fetch_token(GET).type == T_WORD)
	{
		syntax_simple_command(command->simple_command);
		if (fetch_token(GET).type == T_REDIRECT)
			syntax_redirects(command->redirects);
	}
	else if (fetch_token(GET).type == T_REDIRECT)
	{
		syntax_redirects(command->redirects);
	}
	else
	{
	}
}
