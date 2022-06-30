/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_redirects.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 04:59:05 by nkim              #+#    #+#             */
/*   Updated: 2022/07/01 01:43:33 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_syntax_redirects(t_ast **ast_redirects)
{
	*ast_redirects = bs_calloc(1, sizeof(t_ast));
	(*ast_redirects)->type = AST_REDIRECTS;
	(*ast_redirects)->data = bs_calloc(1, sizeof(t_redirects));
}

/*
	syntax_redirects
	- check io_redirect syntax error
*/
int	syntax_redirects(t_ast **ast_redirects)
{
	int			flag;
	t_redirects	*redirects;

	flag = SUCCESS_FLAG;
	init_syntax_redirects(ast_redirects);
	redirects = (*ast_redirects)->data;
	if (syntax_io_redirect(&redirects->io_redirect))
		return (ERROR_FLAG);
	if (fetch_token(GET).type == T_REDIRECT)
		flag |= syntax_redirects(&redirects->redirects);
	return (flag);
}
