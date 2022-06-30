/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 18:15:27 by hannkim           #+#    #+#             */
/*   Updated: 2022/06/30 18:23:21 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdio.h>
# include <stdlib.h>

int		bs_isspace(int c);
int		bs_strcmp(char *s1, char *s2);
void	bs_exit_eof(char *command_line);
void	*bs_calloc(size_t count, size_t size);

#endif
