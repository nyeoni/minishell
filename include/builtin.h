/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 03:33:04 by nkim              #+#    #+#             */
/*   Updated: 2022/06/24 03:34:50 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

int		is_builtin(char *exec_path);
void	ft_echo(char **argv);
void	ft_cd(char **argv);
void	ft_pwd(char **argv);
void	ft_env(void);
void	ft_exit(void);
void	ft_export(char **argv);
void	ft_unset(char **argv);

#endif