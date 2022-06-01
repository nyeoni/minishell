/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 17:21:50 by nkim              #+#    #+#             */
/*   Updated: 2021/07/27 18:29:50 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct s_gnl_manager
{
	char		**file_rest;
	char		*line;
	int			max_fd;
}				t_gnl_manager;

size_t			ft_strlen(const char *s);
void			*ft_memset(void *dst, int value, size_t n);
char			*ft_strchr(const char *src, int c);
void			*ft_memmove(void *dst, const void *src, size_t n);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strndup(const char *s1, size_t n);
char			*get_next_line(int fd);

#endif