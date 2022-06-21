/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_analyzer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 14:12:20 by nkim              #+#    #+#             */
/*   Updated: 2022/06/20 19:31:01 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	else for Syntax error
*/
char	*match(t_type type)
{
	t_token	token;

	token = fetch_token(UPDATE);
	printf("match type: %d, value: %s\n", token.type, token.value);
	if (token.type == type)
		return (token.value);
	else
	{
		return (NULL);
	}
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
	syntax_pipe_line(ast);
	return (ast);
}
