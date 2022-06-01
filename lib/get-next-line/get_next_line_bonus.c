/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 17:42:11 by nkim              #+#    #+#             */
/*   Updated: 2021/07/27 18:25:09 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_memset(void *dst, int value, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*((char *)dst + i) = value;
		i++;
	}
	return (dst);
}

void	manage_line(char **file_rest,
	t_gnl_manager *gnl_m, int r_bytes)
{
	char	*next_sp;
	char	*tmp;
	int		i;

	next_sp = ft_strchr(gnl_m->line, '\n');
	if (r_bytes == -1 || (r_bytes == 0 && !next_sp))
	{
		i = 0;
		while (i <= gnl_m->max_fd && (gnl_m->file_rest)[i] == NULL)
			i++;
		if (i == gnl_m->max_fd + 1)
		{
			free(gnl_m->file_rest);
			gnl_m->file_rest = NULL;
		}
	}
	if (next_sp && *(next_sp + 1))
	{
		*file_rest = ft_strndup(next_sp + 1, ft_strlen(next_sp + 1));
		tmp = gnl_m->line;
		gnl_m->line = ft_strndup(gnl_m->line, next_sp - gnl_m->line + 1);
		free(tmp);
	}
}

void	init_gnl_manager(t_gnl_manager *gnl_m, int fd)
{
	char	**tmp;

	if (!gnl_m->file_rest)
	{
		gnl_m->file_rest = (char **)malloc(sizeof(char *) * (fd + 1));
		ft_memset(gnl_m->file_rest, 0, sizeof(char *) * (fd + 1));
		gnl_m->max_fd = fd;
	}
	else if (fd > gnl_m->max_fd)
	{
		tmp = gnl_m->file_rest;
		gnl_m->file_rest = (char **)malloc(sizeof(char *) * (fd + 1));
		ft_memset(gnl_m->file_rest, 0, sizeof(char *) * (fd + 1));
		ft_memmove(gnl_m->file_rest, tmp,
			sizeof(char *) * (gnl_m->max_fd + 1));
		free(tmp);
		tmp = NULL;
		gnl_m->max_fd = fd;
	}
}

char	*init_all(char *buf, t_gnl_manager *fm, int fd)
{
	char	*line;
	char	*tmp;

	init_gnl_manager(fm, fd);
	if ((fm->file_rest)[fd])
	{
		tmp = ft_strndup((fm->file_rest)[fd], ft_strlen((fm->file_rest)[fd]));
		free((fm->file_rest)[fd]);
		(fm->file_rest)[fd] = NULL;
	}
	else
		tmp = ft_strndup("", 0);
	line = ft_strjoin(tmp, buf);
	free(tmp);
	return (line);
}

char	*get_next_line(int fd)
{
	static t_gnl_manager	gnl_m;
	char					buffer[BUFFER_SIZE + 1];
	char					*tmp;
	int						r_bytes;

	ft_memset(buffer, 0, BUFFER_SIZE + 1);
	r_bytes = read(fd, buffer, BUFFER_SIZE);
	if (fd < 0 || BUFFER_SIZE <= 0 || r_bytes == -1)
		return (0);
	gnl_m.line = init_all(buffer, &gnl_m, fd);
	while (!(ft_strchr(gnl_m.line, '\n')) && r_bytes > 0)
	{
		ft_memset(buffer, 0, BUFFER_SIZE + 1);
		r_bytes = read(fd, buffer, BUFFER_SIZE);
		tmp = gnl_m.line;
		gnl_m.line = ft_strjoin(gnl_m.line, buffer);
		free(tmp);
	}
	manage_line(&(gnl_m.file_rest)[fd], &gnl_m, r_bytes);
	if (r_bytes == -1 || (r_bytes == 0 && !gnl_m.line[0]))
	{
		free(gnl_m.line);
		gnl_m.line = NULL;
	}
	return (gnl_m.line);
}
