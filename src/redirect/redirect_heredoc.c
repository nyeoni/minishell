/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_heredoc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 20:01:20 by nkim              #+#    #+#             */
/*   Updated: 2022/06/29 16:37:21 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// cmd 받을 수 있는지
// static void	signal_heredoc(void)
// {
// 	signal(SIGQUIT, SIG_IGN);
// 	if (is_builtin(g_manager.command_line))
// 		signal(SIGINT, handle_sigint);
// 	else
// 		signal(SIGINT, SIG_DFL);
// }

/*
	signal 받으면 작성중이던 file 삭제를 해야함 (main while문 안에서 삭제해야함)
		open, unlink 사용하면 프로세스 종료되면 파일 삭제됨
	ctrl+d EOF 왔을 때, readline prompt 에 개행 오는 건 ㄱㅊ
*/
// TODO: builtin이면 SIG_DFL 아니라, 프롬프트를 띄우기 -> builtin인지 확인 어떻게 할 건지 
// TODO: 여러 pipe에서 heredoc 사용할 경우 -> file name "./herdoc"으로 동일해도 괜찮은지 check!
int	redirect_heredoc(char *end_text)
{
	int		fd;
	char	*line;

	rl_instream->_file = 3;
	fd = open("./heredoc", O_WRONLY | O_CREAT | O_EXCL | O_TRUNC, 0644);
	if (fd < 0)
		throw_error_exit("", strerror(errno), EXIT_FAILURE);
	while (1)
	{
		line = readline(PS2);
		if (!line || !ft_strcmp(line, end_text))
		{
			free(line);
			return (redirect_in_file("./heredoc"));
		}
		ft_putendl_fd(line, fd);
		free(line);
	}
}
