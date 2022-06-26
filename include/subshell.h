/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subshell.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 17:14:36 by nkim              #+#    #+#             */
/*   Updated: 2022/06/26 18:28:34 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUBSHELL_H
# define SUBSHELL_H

#include <unistd.h>
#include "ast.h"

pid_t	create_subshell(t_pipe_line *pipe_line);
void	wait_subshell(pid_t last_pid);

#endif