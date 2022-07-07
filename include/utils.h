/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 18:15:27 by hannkim           #+#    #+#             */
/*   Updated: 2022/07/05 18:12:47 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		bs_isspace(int c);
int		bs_strcmp(char *s1, char *s2);
void	bs_exit_eof(char *command_line);
void	*bs_calloc(size_t count, size_t size);
char	*bs_find_path(char *cmd);

#endif
