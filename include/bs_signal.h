/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bs_signal.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:01:22 by hannkim           #+#    #+#             */
/*   Updated: 2022/07/01 16:11:05 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BS_SIGNAL_H
# define BS_SIGNAL_H

# include <signal.h>
# include <unistd.h>
# include <sys/ioctl.h>
# include "minishell.h"

void	init_signal(void);
void	change_signal(void);
void	handle_signal_heredoc(void);
void	multishell_signal(void);

#endif
