/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 21:38:00 by hannkim           #+#    #+#             */
/*   Updated: 2022/06/29 21:38:02 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	change_sigint(int signum)
{
	if (signum != SIGINT)
		return ;
	write(1, "\n", 1);
}

/* do nothing */
static void	change_sigquit(int signum)
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
	signal(SIGINT, change_sigint);
	signal(SIGQUIT, change_sigquit);
}
