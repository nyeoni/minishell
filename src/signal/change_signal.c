/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 21:38:00 by hannkim           #+#    #+#             */
/*   Updated: 2022/07/01 16:29:27 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bs_signal.h"

static void	handle_sigint_change(int signum)
{
	if (signum != SIGINT)
		return ;
	write(1, "\n", 1);
}

/* do nothing */
static void	handle_sigquit_change(int signum)
{
	if (signum != SIGQUIT)
		return ;
}

/*
	before fork, change handler
	SIGQUIT don't have to ignore in execve()
	if use SIG_DFL, parent process will exit with child process
*/
void	change_signal(void)
{
	signal(SIGINT, handle_sigint_change);
	signal(SIGQUIT, handle_sigquit_change);
}
