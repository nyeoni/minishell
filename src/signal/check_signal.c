/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_signal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:00:23 by nkim              #+#    #+#             */
/*   Updated: 2022/06/29 00:20:32 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* rl_replace_line : buffer flush */
static void	handle_sigint(int signum)
{
	if (signum != SIGINT)
		return ;
	write(1, "\n", 1);
	rl_replace_line("", 1);
	rl_on_new_line();
	rl_redisplay();
	g_manager.exit_code = 1;
}

/* after parsing, before execute command */
static void	reset_sigint(int signum)
{
	if (signum != SIGINT)
		return ;
	write(1, "\n", 1);
}

static void	reset_sigquit(int signum)
{
	if (signum != SIGQUIT)
		return ;
}

/* SIGINT : ctrl + c, SIGQUIT : ctrl + \ */
void	check_signal(void)
{
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, SIG_IGN);
}

/*
	SIG_DFL를 하게 되면, 부모 프로세스에서 fork 직전에 바꾸기 때문에 부모 프로세스도 같이 종료됨
*/
void	reset_signal(void)
{
	signal(SIGINT, reset_sigint);
	signal(SIGQUIT, reset_sigquit);
}
