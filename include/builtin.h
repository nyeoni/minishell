/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 03:33:04 by nkim              #+#    #+#             */
/*   Updated: 2022/07/07 13:40:35 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "error.h"
# include "libft.h"

int				is_builtin(char *exec_path);
int				check_option(char *argv);
int				ft_echo(char **argv);
int				ft_cd(char **argv);
int				ft_pwd(char **argv);
int				ft_env(char **argv);
int				ft_exit(char **argv);
int				ft_export(char **argv);
int				ft_unset(char **argv);
unsigned char	check_exit_arg(char *arg);
int				valid_exit_code(const char *s);

#endif