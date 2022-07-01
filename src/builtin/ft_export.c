/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 23:58:45 by hannkim           #+#    #+#             */
/*   Updated: 2022/07/01 14:19:30 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	env_quotes(void)
{
	t_env	*ptr;

	ptr = g_manager.env;
	while (ptr)
	{
		ft_putstr_fd(ptr->name, STDOUT_FILENO);
		if (ptr->value)
		{
			write(STDOUT_FILENO, "=\"", 2);
			ft_putstr_fd(ptr->value, STDOUT_FILENO);
			write(STDOUT_FILENO, "\"", 2);
		}
		ft_putendl_fd("", STDOUT_FILENO);
		ptr = ptr->next;
	}
}

static void	exec_export(char *argv)
{
	char	*name;
	char	*value;
	t_env	*ptr;

	name = get_env_name(argv);
	value = get_env_value(argv);
	ptr = get_env(name);
	if (ptr)
	{
		if (value)
		{
			if (ptr->value)
				free(ptr->value);
			ptr->value = value;
		}
		free(name);
	}
	else
		add_env(name, get_env_value(argv));
}

/*
	Invalid env_name -> exit_code = EXIT_FAILURE
	Invalid option -> exit_code = 2
*/
int	ft_export(char **argv)
{
	int	exit_code;

	exit_code = EXIT_SUCCESS;
	if (!argv[1])
	{
		env_quotes();
		return (exit_code);
	}
	argv++;
	while (*argv)
	{
		if (check_option(*argv) == EXIT_FAILURE)
			exit_code = throw_error_usage("export", *argv) + 1;
		else if (valid_env_name(*argv) == EXIT_FAILURE)
			exit_code = throw_error_env("export", *argv);
		else
			exec_export(*argv);
		argv++;
	}
	return (exit_code);
}
