/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backup_stdin_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 18:29:57 by nkim              #+#    #+#             */
/*   Updated: 2022/06/27 19:14:48 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	backup_stdin_fd(int *fd)
{
	*fd = dup(STDIN_FILENO);
	if (*fd == -1)
		return (throw_error("dup", NULL, strerror(errno)));
	return (SUCCESS_FLAG);
}
