/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 02:08:50 by nkim              #+#    #+#             */
/*   Updated: 2022/06/28 00:13:07 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "token.h"
# include <sys/errno.h>

# define SYNTAX_ERR 258

int	throw_error(char *cmd, char *argv, char *err);
int	throw_error_env(char *cmd, char *argv);
int	throw_error_exit(char *cmd, char *err, int exit_code);
int	throw_error_usage(char *cmd, char *argv);
int	throw_error_syntax(t_token token);

#endif