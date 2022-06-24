/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_general.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 09:22:30 by hannkim           #+#    #+#             */
/*   Updated: 2022/06/24 16:23:08 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_count(void)
{
	t_env	*ptr;
	int		count;

	ptr = g_manager.env;
	count = 0;
	while (ptr)
	{
		count++;
		ptr = ptr->next;
	}
	return (count);
}

/* env list -> char ** */
static char	**get_string_env(void)
{
	t_env	*ptr;
	char	**ret;
	char	*tmp;
	int		count;
	int		i;

	ptr = g_manager.env;
	count = get_count();
	ret = (char **)ft_calloc(count + 1, sizeof(char *));
	if (!ret)
		exit(EXIT_FAILURE);
	i = 0;
	while (ptr)
	{
		tmp = ft_strjoin(ptr->name, "=");
		ret[i] = ft_strjoin(tmp, ptr->value);
		free(tmp);
		ptr = ptr->next;
		i++;
	}
	return (ret);
}

/* find and return file's path (filename) */
static char	*find_file(char *cmd, char **path)
{
	char		*filename;
	char		*tmp;
	struct stat	*buf;
	int			i;

	i = 0;
	while (path[i])
	{
		tmp = ft_strjoin(path[i], "/");
		filename = ft_strjoin(tmp, cmd);
		free(tmp);
		if (stat(filename, buf) != -1)
			return (filename);
		free(filename);
		i++;
	}
	return (ft_strdup(cmd));
}

/* error -> envp, filename free? -> exit? */
void	exec_general(char **argv)
{
	char	**envp;
	char	**path;
	char	*filename;
	int		i;

	path = ft_split(get_env("PATH")->value, ':');
	filename = find_file(argv[0], path);
	envp = get_string_env();
	i = 0;
	while (path[i])
	{
		free(path[i]);
		i++;
	}
	free(path);
	signal(SIGQUIT, SIG_DFL);
	execve(filename, argv, envp);
	exit(EXIT_FAILURE);
}
