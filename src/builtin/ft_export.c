/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 18:20:31 by hannkim           #+#    #+#             */
/*   Updated: 2022/06/20 12:18:26 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	env_quotes(void)
{
	t_env	*ptr;

	ptr = manager.env;
	while (ptr)
	{
		ft_putstr_fd(ptr->name, STDOUT_FILENO);
		write(STDOUT_FILENO, "=\"", 2);
		ft_putstr_fd(ptr->value, STDOUT_FILENO);
		write(STDOUT_FILENO, "\"\n", 2);
		ptr = ptr->next;
	}
}

static void	exec_export(char *argv)
{
	t_env	*ptr;
	char	*name;

	name = get_name(argv);
	ptr = get_env(name);
	if (ptr)
	{
		free(ptr->value);
		ptr->value = get_value(argv);
		free(name);
	}		
	else
		add_env(name, get_value(argv));
}

void	ft_export(char **argv)
{
	if (!argv[1])
	{
		env_quotes();
		return ;
	}
	argv++;
	while (*argv)
	{
		if (ft_strchr(*argv, '='))
		{
			if (is_valid_identifier(*argv) == EXIT_FAILURE)
				throw_error_env("export", *argv);
			else
				exec_export(*argv);
		}
		argv++;
	}
}
