/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 21:17:33 by nkim              #+#    #+#             */
/*   Updated: 2022/06/28 18:24:37 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "test.h"

t_manager	g_manager;

void	init_manger(char *command_line)
{
	g_manager.command_line = command_line;
	g_manager.rc = 0;
	g_manager.quote_error = 0;
}

void	init_env(char **envp)
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
	init_env(envp);
	while (1)
	{
		check_signal();
		command_line = readline(PS1);
		ft_exit_eof(command_line);
		if (*command_line)
			add_history(command_line);
		init_manger(command_line);
		ast = syntax_analyzer();
		test_ast(ast);
		if (g_manager.exit_code == SYNTAX_ERR)
		{
			free(command_line);
			continue ;
		}
		exec_ast(ast);
		free(command_line);
	}
	return (0);
}
