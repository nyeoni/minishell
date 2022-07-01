/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multishell_signal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:28:29 by hannkim           #+#    #+#             */
/*   Updated: 2022/07/01 16:31:45 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bs_signal.h"

static void	handle_sigint_multishell(int signum)
{
	if (signum != SIGINT)
		return ;
}

/* do nothing */
static void	handle_sigquit_multishell(int signum)
{
	if (signum != SIGQUIT)
		return ;
}

void	multishell_signal(void)
{
	signal(SIGINT, handle_sigint_multishell);
	signal(SIGQUIT, handle_sigquit_multishell);
}
