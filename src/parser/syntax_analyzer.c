/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_analyzer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 14:12:20 by nkim              #+#    #+#             */
/*   Updated: 2022/06/28 17:34:35 by nkim             ###   ########.fr       */
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
	g_manager.exit_code = SYNTAX_ERR;
	return (NULL);
}

/*
	TODO: NULL일때 prompt 가 newLine 받는 상태로
*/
t_ast	*syntax_analyzer(void)
{
	t_ast	*ast;

	fetch_token(UPDATE);
	if (fetch_token(GET).type == T_NULL)
		return (NULL);
	syntax_pipe_line(&ast);
	return (ast);
}
