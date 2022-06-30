/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_io_redirect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 22:11:55 by nkim              #+#    #+#             */
/*   Updated: 2022/06/30 17:00:04 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_io_redirect(t_io_redirect *io_redirect)
{
	if (io_redirect->redirect_op == R_HEREDOC)
		if (unlink(io_redirect->file_path) == -1)
			perror("hihihi");
	if (io_redirect->file_path)
		free(io_redirect->file_path);
	if (io_redirect->end_text)
		free(io_redirect->end_text);
	free(io_redirect);
}
