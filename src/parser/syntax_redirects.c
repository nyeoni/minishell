/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_redirects.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 04:59:05 by nkim              #+#    #+#             */
/*   Updated: 2022/07/03 20:18:37 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

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
	return (SUCCESS_FLAG);
}
