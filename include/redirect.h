/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 18:27:34 by nkim              #+#    #+#             */
/*   Updated: 2022/06/29 21:16:00 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECT_H
# define REDIRECT_H

# define BACKUP_FD 255

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

int	redirect_in_file(char *file_path);
int	redirect_out_file(char *file_path);
int	redirect_append_file(char *file_path);
int	redirect_heredoc(char *end_text, char *heredoc_path);
int	backup_std_fd(int std_fd[3]);
int	reset_std_fd(int std_fd[3]);

#endif