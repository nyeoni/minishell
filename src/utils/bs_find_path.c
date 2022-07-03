/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bs_find_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 15:10:47 by hannkim           #+#    #+#             */
/*   Updated: 2022/07/03 15:15:31 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_path(char **path)
{
	int	i;

	i = 0;
	while (path[i])
	{
		free(path[i]);
		i++;
	}
	free(path);
}

static char	**split_path(void)
{
	char	**path;

	if (get_env(PATHENV))
		path = ft_split(get_env(PATHENV)->value, ':');
	else
	{
		path = (char **)bs_calloc(2, sizeof(char *));
		*path = ft_strdup(".");
	}
	return (path);
}

/* find and return file's path (filename) */
char	*bs_find_path(char *cmd)
{
	struct stat	buf;
	char		**path;
	char		*filename;
	char		*tmp;
	int			i;

	i = 0;
	path = split_path();
	while (path[i])
	{
		tmp = ft_strjoin(path[i], "/");
		filename = ft_strjoin(tmp, cmd);
		free(tmp);
		if (stat(filename, &buf) != -1)
			return (filename);
		free(filename);
		i++;
	}
	free_path(path);
	return (ft_strdup(cmd));
}
