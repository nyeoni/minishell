/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 21:26:05 by nkim              #+#    #+#             */
/*   Updated: 2022/06/26 21:32:17 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "ast.h"

int	exec_builtin(char **argv);
int	exec_general(char **argv);
int	exec_ast(t_ast *ast);
int	exec_command(t_command *command);
int	exec_subshell(t_pipe_line *pipe_line);
int	exec_single_command(t_command *command);
int	exec_simple_command(t_simple_command *simple_command);
int	exec_io_redirect(t_io_redirect *io_redirect);

#endif