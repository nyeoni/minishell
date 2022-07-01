/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multishell_signal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:28:29 by hannkim           #+#    #+#             */
/*   Updated: 2022/07/01 16:05:17 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bs_signal.h"

static void	multishell_sigint(int signum)
{
	if (signum != SIGINT)
		return ;
}

/* do nothing */
static void	multishell_sigquit(int signum)
{
	if (signum != SIGQUIT)
		return ;
}

void	multishell_signal(void)
{
	signal(SIGINT, multishell_sigint);
	signal(SIGQUIT, multishell_sigquit);
}
