/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_std_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 19:11:30 by nkim              #+#    #+#             */
/*   Updated: 2022/06/28 20:18:26 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	reset_std_fd(int std_fd[3])
{
	if (dup2(std_fd[READ], STDIN_FILENO) == -1)
		return (throw_error_exit("dup2", strerror(errno), EXIT_FAILURE));
	if (dup2(std_fd[WRITE], STDOUT_FILENO) == -1)
		return (throw_error_exit("dup2", strerror(errno), EXIT_FAILURE));
	if (dup2(std_fd[ERROR], STDERR_FILENO) == -1)
		return (throw_error_exit("dup2", strerror(errno), EXIT_FAILURE));
	return (SUCCESS_FLAG);
}
