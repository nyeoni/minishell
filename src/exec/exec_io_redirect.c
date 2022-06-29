/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_io_redirect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 21:31:57 by nkim              #+#    #+#             */
/*   Updated: 2022/06/29 02:19:55 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_io_redirect(t_io_redirect *io_redirect)
{
	printf("exec_io_redirect\n");
	if (io_redirect->redirect_op == R_IN)
		return (redirect_in_file(io_redirect->file_path));
	else if (io_redirect->redirect_op == R_OUT)
		return (redirect_out_file(io_redirect->file_path));
	else if (io_redirect->redirect_op == R_HEREDOC)
		return (redirect_heredoc(io_redirect->file_path));
	else if (io_redirect->redirect_op == R_APPEND)
		return (redirect_append_file(io_redirect->file_path));
	else
		return (ERROR_FLAG);
}
