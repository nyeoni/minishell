/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 18:20:31 by hannkim           #+#    #+#             */
/*   Updated: 2022/06/20 11:26:51 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	env_quotes(void)
{
	t_env *ptr;

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

void	ft_export(char **argv)
{
	t_env	*ptr;
	char	*name;

	if (!argv[1])		// export
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
			{
				name = get_name(*argv);
				ptr = get_env(name);
				if (ptr)	// 해당 변수명이 이미 만들어져 있는 경우 -> 덮어 쓰기
				{
					free(ptr->value);
					ptr->value = get_value(*argv);
					free(name);
				}		
				else
					add_env(name, get_value(*argv));
			}
		}
		argv++;
	}
}
