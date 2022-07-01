/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 04:50:24 by nkim              #+#    #+#             */
/*   Updated: 2022/07/01 16:12:07 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

char	*create_heredoc_path(void)
{
	unsigned static int	cnt;
	char				*cnt_arr;
	char				*heredoc_path;
	char				*tmpdir;

	if (get_env(TMPENV) == NULL)
		tmpdir = ft_strjoin(TMPDIR, TMPKEY);
	else
		tmpdir = ft_strjoin(get_env(TMPENV)->value, TMPKEY);
	cnt_arr = ft_itoa(cnt);
	heredoc_path = ft_strjoin(tmpdir, cnt_arr);
	free(tmpdir);
	free(cnt_arr);
	cnt++;
	return (heredoc_path);
}

static int	exec_redirect_heredoc(t_ast **ast)
{
	int				flag;
	t_token			token;
	t_redirects		*redirects;
	t_io_redirect	*io_redirect;

	token.type = T_NULL;
	token.value = NULL;
	flag = SUCCESS_FLAG;
	redirects = NULL;
	io_redirect = NULL;
	if (*ast && (*ast)->type == AST_REDIRECTS)
		redirects = (*ast)->data;
	if (redirects && redirects->io_redirect)
		io_redirect = redirects->io_redirect;
	if (io_redirect->redirect_op == R_HEREDOC)
	{
		if (io_redirect->end_text == NULL)
			return (throw_error_syntax(token));
		io_redirect->file_path = create_heredoc_path();
		flag = redirect_heredoc(io_redirect->end_text, io_redirect->file_path);
	}
	if (redirects->redirects)
		flag |= exec_redirect_heredoc(&redirects->redirects);
	return (flag);
}

int	exec_heredoc(t_ast **ast)
{
	int			flag;
	t_pipe_line	*pipe_line;
	t_command	*command;

	flag = SUCCESS_FLAG;
	pipe_line = NULL;
	command = NULL;
	if (*ast && (*ast)->type == AST_PIPELINE)
		pipe_line = (*ast)->data;
	if (pipe_line && pipe_line->command->type == AST_COMMAND)
		command = pipe_line->command->data;
	if (command && command->redirects)
		flag = exec_redirect_heredoc(&command->redirects);
	if (pipe_line && pipe_line->pipe_line)
		flag |= exec_heredoc(&pipe_line->pipe_line);
	return (flag);
}
