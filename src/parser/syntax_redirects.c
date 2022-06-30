/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_redirects.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 04:59:05 by nkim              #+#    #+#             */
/*   Updated: 2022/06/30 18:21:17 by hannkim          ###   ########.fr       */
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
	t_redirects	*redirects;

	init_syntax_redirects(ast_redirects);
	redirects = (*ast_redirects)->data;
	if (syntax_io_redirect(&redirects->io_redirect))
		return (ERROR_FLAG);
	if (fetch_token(GET).type == T_REDIRECT)
		syntax_redirects(&redirects->redirects);
	return (SUCCESS_FLAG);
}
