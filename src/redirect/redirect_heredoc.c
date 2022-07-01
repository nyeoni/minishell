/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_heredoc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 20:01:20 by nkim              #+#    #+#             */
/*   Updated: 2022/07/01 16:14:43 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "bs_signal.h"

static int	end_of_heredoc(char *line, int fd)
{
	free(line);
	if (close(fd) == -1)
		return (throw_error_exit("close", strerror(errno), EXIT_FAILURE));
	return (SUCCESS_FLAG);
}

int	redirect_heredoc(char *end_text, char *heredoc_path)
{
	int		fd;
	char	*line;

	handle_signal_heredoc();
	fd = open(heredoc_path, O_WRONLY | O_CREAT | O_EXCL | O_TRUNC, 0644);
	if (fd < 0)
		throw_error_exit("open", strerror(errno), EXIT_FAILURE);
	while (!g_manager.exit_code)
	{
		line = readline(PS2);
		if (!line || !bs_strcmp(line, end_text))
			return (end_of_heredoc(line, fd));
		ft_putendl_fd(line, fd);
		free(line);
	}
	if (close(fd) == -1)
		throw_error_exit("close", strerror(errno), EXIT_FAILURE);
	return (EXIT_FAILURE);
}
