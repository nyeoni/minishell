/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 03:33:04 by nkim              #+#    #+#             */
/*   Updated: 2022/07/01 15:44:43 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

int		is_builtin(char *exec_path);
int		check_option(char *argv);
int		ft_echo(char **argv);
int		ft_cd(char **argv);
int		ft_pwd(char **argv);
int		ft_env(char **argv);
int		ft_exit(char **argv);
int		ft_export(char **argv);
int		ft_unset(char **argv);

#endif