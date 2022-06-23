/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_redirects.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 04:59:05 by nkim              #+#    #+#             */
/*   Updated: 2022/06/23 14:44:04 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	syntax_redirects(t_ast **ast_redirects)
{
	t_redirects	*redirects;

	*ast_redirects = ft_calloc(1, sizeof(t_ast));
	(*ast_redirects)->type = AST_REDIRECTS;
	(*ast_redirects)->data = ft_calloc(1, sizeof(t_redirects));
	redirects = (*ast_redirects)->data;
	syntax_io_redirect(&redirects->io_redirect);
	if (fetch_token(GET).type == T_REDIRECT)
		syntax_redirects(&redirects->redirects);
}
