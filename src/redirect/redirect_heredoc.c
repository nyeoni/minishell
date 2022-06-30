/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_heredoc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 20:01:20 by nkim              #+#    #+#             */
/*   Updated: 2022/06/29 23:20:45 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	"rl_instream->_file = 3" means standard input -> 
*/
int	redirect_heredoc(char *end_text, char *heredoc_path)
{
	int		fd;
	char	*line;

	signal(SIGINT, handle_sigint_heredoc);
	signal(SIGQUIT, SIG_IGN);
	rl_instream->_file = BACKUP_FD;
	fd = open(heredoc_path, O_WRONLY | O_CREAT | O_EXCL | O_TRUNC, 0644);
	if (fd < 0)
		throw_error_exit("", strerror(errno), EXIT_FAILURE);
	while (!g_manager.exit_code)
	{
		line = readline(PS2);
		if (!line || !ft_strcmp(line, end_text))
		{
			free(line);
			close(fd);
			return (redirect_in_file(heredoc_path));
		}
		ft_putendl_fd(line, fd);
		free(line);
	}
	close(fd);
	return (EXIT_FAILURE);
}
