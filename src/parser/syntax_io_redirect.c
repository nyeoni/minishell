/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_io_redirect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 04:59:57 by nkim              #+#    #+#             */
/*   Updated: 2022/06/23 17:04:59 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	syntax_io_redirect(t_io_redirect **io_redirect)
{
	*io_redirect = ft_calloc(1, sizeof(t_io_redirect));
	(*io_redirect)->redirect_op = match(T_REDIRECT);
	if (!ft_strncmp((*io_redirect)->redirect_op, "<<", 3))
		(*io_redirect)->file_path = get_combined_heredoc_word();
	else
		(*io_redirect)->file_path = get_combined_word();
}
