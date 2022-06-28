/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_redirects.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 04:59:05 by nkim              #+#    #+#             */
/*   Updated: 2022/06/28 18:01:56 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	syntax_redirects
	- check io_redirect syntax error
*/
int	syntax_redirects(t_ast **ast_redirects)
{
	t_redirects	*redirects;

	*ast_redirects = ft_calloc(1, sizeof(t_ast));
	(*ast_redirects)->type = AST_REDIRECTS;
	(*ast_redirects)->data = ft_calloc(1, sizeof(t_redirects));
	redirects = (*ast_redirects)->data;
	if (syntax_io_redirect(&redirects->io_redirect))
		return (ERROR_FLAG);
	if (fetch_token(GET).type == T_REDIRECT)
		syntax_redirects(&redirects->redirects);
	return (SUCCESS_FLAG);
}
