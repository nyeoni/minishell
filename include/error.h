/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 02:08:50 by nkim              #+#    #+#             */
/*   Updated: 2022/06/24 02:46:11 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include <sys/errno.h>

void	throw_error(char *cmd, char *argv, char *err);
void	throw_error_env(char *cmd, char *argv);
void	throw_error_exit(char *cmd, char *err, int exit_code);

#endif