/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signal_heredoc.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:57:12 by hannkim           #+#    #+#             */
/*   Updated: 2022/07/01 16:11:17 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bs_signal.h"

static void	handle_sigint_heredoc(int signum)
{
	if (signum != SIGINT)
		return ;
	ioctl(STDIN_FILENO, TIOCSTI, "\n");
	g_manager.exit_code = 1;
	return ;
}

void	handle_signal_heredoc(void)
{
	signal(SIGINT, handle_sigint_heredoc);
	signal(SIGQUIT, SIG_IGN);
}
