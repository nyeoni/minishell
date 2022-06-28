/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throw_error_syntax.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 23:59:10 by hannkim           #+#    #+#             */
/*   Updated: 2022/06/28 20:26:01 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
   throw_error_syntax
*/
int	throw_error_syntax(t_token token)
{
	ft_putstr_fd("blackhole-shell: syntax error near unexpected token `", 2);
	if (token.type == T_PIPE)
		ft_putstr_fd(token.value, 2);
	else
		ft_putstr_fd("newline", 2);
	ft_putendl_fd("'", 2);
	g_manager.exit_code = EXIT_SYNTAXERR;
	return (ERROR_FLAG);
}
