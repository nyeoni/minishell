/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 02:08:50 by nkim              #+#    #+#             */
/*   Updated: 2022/07/05 18:12:47 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "libft.h"
# include "minishell.h"
# include "token.h"
# include <stdlib.h>
# include <sys/errno.h>
# include <unistd.h>

# define ERROR_FLAG -1
# define SUCCESS_FLAG 0
# define EXIT_EACCES 126
# define EXIT_ENOENT 127
# define EXIT_MAX 255
# define EXIT_SYNTAXERR 258

int	throw_error(char *cmd, char *argv, char *err);
int	throw_error_env(char *cmd, char *argv);
int	throw_error_exit(char *cmd, char *err, int exit_code);
int	throw_error_usage(char *cmd, char *argv);
int	throw_error_syntax(t_token token);

#endif