/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_io_redirect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 22:11:55 by nkim              #+#    #+#             */
/*   Updated: 2022/06/29 20:57:12 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_io_redirect(t_io_redirect *io_redirect)
{
	if (io_redirect->file_path)
		free(io_redirect->file_path);
	if (io_redirect->heredoc_path)
	{
		unlink(io_redirect->heredoc_path);
		free(io_redirect->heredoc_path);
	}
	free(io_redirect);
}
