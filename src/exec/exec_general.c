/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_general.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:00:00 by nkim              #+#    #+#             */
/*   Updated: 2022/07/03 16:12:58 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

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
	ret = (char **)bs_calloc(count + 1, sizeof(char *));
	if (!ret)
		exit(EXIT_FAILURE);
	i = 0;
	while (ptr && ptr->value)
	{
		tmp = ft_strjoin(ptr->name, "=");
		ret[i] = ft_strjoin(tmp, ptr->value);
		free(tmp);
		ptr = ptr->next;
		i++;
	}
	return (ret);
}

static int	error_execve(char *argv)
{
	int	exit_code;

	exit_code = EXIT_FAILURE;
	if (errno == ENOENT)
	{
		exit_code = EXIT_ENOENT;
		throw_error(argv, NULL, "command not found");
	}
	else if (errno == EACCES)
	{
		exit_code = EXIT_EACCES;
		throw_error(argv, NULL, strerror(errno));
	}
	return (exit_code);
}

/* error -> envp, filename free? -> exit? */
int	exec_general(char **argv)
{
	char	**envp;
	char	*filename;

	envp = get_string_env();
	if (ft_strchr(*argv, '/') == NULL)
	{
		if (get_env(PATHENV))
			filename = bs_find_path(*argv);
	}
	else
		filename = ft_strdup(*argv);
	if (!argv[0][0])
		throw_error_exit(argv[0], "command not found", EXIT_ENOENT);
	execve(filename, argv, envp);
	return (error_execve(*argv));
}
