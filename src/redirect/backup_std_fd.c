/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backup_std_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 18:29:57 by nkim              #+#    #+#             */
/*   Updated: 2022/06/29 21:24:36 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	backup_std_fd(int std_fd[3])
{
	std_fd[READ] = dup2(STDIN_FILENO, BACKUP_FD);
	std_fd[WRITE] = dup(STDOUT_FILENO);
	std_fd[ERROR] = dup(STDERR_FILENO);
	if (std_fd[READ] == -1 || std_fd[WRITE] == -1 || std_fd[ERROR] == -1)
		throw_error_exit("dup", strerror(errno), EXIT_FAILURE);
	return (SUCCESS_FLAG);
}
