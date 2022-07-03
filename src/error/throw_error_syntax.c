/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throw_error_syntax.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 23:59:10 by hannkim           #+#    #+#             */
/*   Updated: 2022/07/03 16:17:41 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

/*
   throw_error_syntax
*/
int	throw_error_syntax(t_token token)
{
	ft_putstr_fd("blackhole-shell: syntax error near unexpected token `", 2);
	if (token.type == T_PIPE)
		ft_putstr_fd(token.value, STDERR_FILENO);
	else
		ft_putstr_fd("newline", STDERR_FILENO);
	ft_putendl_fd("'", STDERR_FILENO);
	g_manager.exit_code = EXIT_SYNTAXERR;
	return (ERROR_FLAG);
}
