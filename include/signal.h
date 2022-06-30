/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:01:22 by hannkim           #+#    #+#             */
/*   Updated: 2022/06/30 16:03:04 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNAL_H
# define SIGNAL_H

# include <signal.h>

void	ft_exit_eof(char *command_line);
void	init_signal(void);
void	change_signal(void);
void	handle_signal_heredoc(void);

#endif
