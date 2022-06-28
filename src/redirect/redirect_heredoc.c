/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_heredoc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 20:01:20 by nkim              #+#    #+#             */
/*   Updated: 2022/06/29 02:47:16 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// 자식 프로세스라고 가정
static void	signal_heredoc(int signum)
{
	exit(EXIT_FAILURE);
}

static int	ft_strcmp(char *s1, char *s2)
{
	size_t	n;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (s1_len > s2_len)
		n = s1_len;
	else
		n = s2_len;
	return (ft_strncmp(s1, s2, n));
}

/*
	signal 받으면 작성중이던 file 삭제를 해야함 (main while문 안에서 삭제해야함)
		open, unlink 사용하면 프로세스 종료되면 파일 삭제됨
	ctrl+d EOF 왔을 때, readline prompt 에 개행 오는 건 ㄱㅊ
*/
// TODO: builtin이면 SIG_DFL 아니라, 프롬프트를 띄우기
int	redirect_heredoc(char *end_text, char *cmd)
{
	int		fd;
	char	*line;

	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_IGN);
	fd = open("./heredoc", O_RDWR | O_CREAT | O_EXCL | O_TRUNC, 0600);
	if (fd < 0 || unlink("./heredoc") < 0)
		throw_error_exit("", strerror(errno), EXIT_FAILURE);
	while (1)
	{
		line = readline("> ");
		if (!line || !ft_strcmp(line, end_text))
			break ;
		ft_putendl_fd(line, fd);
		free(line);
	}
	if (dup2(fd, STDIN_FILENO) == -1)
		throw_error_exit("dup", strerror(errno), EXIT_FAILURE);
	free(line);
	return (SUCCESS_FLAG);
}
