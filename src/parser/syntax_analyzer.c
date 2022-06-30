/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_analyzer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 14:12:20 by nkim              #+#    #+#             */
/*   Updated: 2022/06/30 18:33:26 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	Syntax error
*/
char	*match(t_type type)
{
	t_token	token;

	token = fetch_token(UPDATE);
	if (token.type == type)
		return (token.value);
	else
		throw_error_syntax(token);
	return (NULL);
}

t_ast	*syntax_analyzer(void)
{
	t_ast	*ast;

	fetch_token(UPDATE);
	if (syntax_pipe_line(&ast) == SUCCESS_FLAG
		&& g_manager.quote_error == SUCCESS_FLAG)
		g_manager.exit_code = EXIT_SUCCESS;
	return (ast);
}
