/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 21:17:33 by nkim              #+#    #+#             */
/*   Updated: 2022/06/26 17:32:24 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "test.h"

t_manager	g_manager;

void	init_manger(char *command_line)
{
	g_manager.command_line = command_line;
	g_manager.rc = 0;
}

void	initiate_env(char **envp)
{
	char	**ptr;

	ptr = envp;
	while (*ptr)
	{
		add_env(get_env_name(*ptr), get_env_value(*ptr));
		ptr++;
	}
}

int	main(int argc, char **argv, char **envp)
{
	char	*command_line;
	t_ast	*ast;

	if (argc > 1)
	{
		printf("ERROR : %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	initiate_env(envp);
	check_signal();
	while (1)
	{
		command_line = readline(PS1);
		ft_exit_eof(command_line);
		if (*command_line)
			add_history(command_line);
		init_manger(command_line);
		ast = syntax_analyzer();
		// test_ast(ast);
		exec_ast(ast);
		// test_builtin();
		free(command_line);
	}
	return (0);
}
