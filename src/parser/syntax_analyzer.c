/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_analyzer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 14:12:20 by nkim              #+#    #+#             */
/*   Updated: 2022/06/20 05:01:01 by nkim             ###   ########.fr       */
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

t_ast	*syntax_analyzer()
{
	t_ast	*AST;

	fetch_token(UPDATE);
	if (fetch_token(GET).type == T_NULL)
		return (NULL); // TODO: NULL일때 prompt 가 newLine 받는 상태로
	syntax_pipe_line(AST);
	return (AST);
}
