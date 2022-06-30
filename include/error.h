/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 02:08:50 by nkim              #+#    #+#             */
/*   Updated: 2022/06/30 13:26:15 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "token.h"
# include <sys/errno.h>

# define EXIT_EACCES 126
# define EXIT_ENOENT 127
# define EXIT_SYNTAXERR 258

int	throw_error(char *cmd, char *argv, char *err);
int	throw_error_env(char *cmd, char *argv);
int	throw_error_exit(char *cmd, char *err, int exit_code);
int	throw_error_usage(char *cmd, char *argv);
int	throw_error_syntax(t_token token);

#endif