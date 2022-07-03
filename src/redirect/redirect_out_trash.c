/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_out_trash.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 16:18:27 by nkim              #+#    #+#             */
/*   Updated: 2022/07/03 16:23:26 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirect.h"

int	redirect_out_trash(void)
{
	int	fd;

	fd = open(TRASH_PATH, O_WRONLY | O_CREAT | O_TRUNC, 00644);
	if (fd < 0)
		return (throw_error(TRASH_PATH, NULL, strerror(errno)));
	if (dup2(fd, STDOUT_FILENO) == -1)
		return (throw_error("dup2", NULL, strerror(errno)));
	if (close(fd) == -1)
		return (throw_error("close", NULL, strerror(errno)));
	return (SUCCESS_FLAG);
}
