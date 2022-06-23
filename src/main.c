/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 21:17:33 by nkim              #+#    #+#             */
/*   Updated: 2022/06/23 17:13:46 by nkim             ###   ########.fr       */
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
		add_env(get_name(*ptr), get_value(*ptr));
		ptr++;
	}
}

void	execute_cmd(char **argv)
{
	if (!ft_strncmp(*argv, "cd", 3))
		ft_cd(argv);
	else if (!ft_strncmp(*argv, "echo", 5))
		ft_echo(argv);
	else if (!ft_strncmp(*argv, "pwd", 4))
		ft_pwd(argv);
	else if (!ft_strncmp(*argv, "env", 4))
		ft_env();
	else if (!ft_strncmp(*argv, "exit", 5))
		ft_exit();
	else if (!ft_strncmp(*argv, "export", 7))
		ft_export(argv);
	else if (!ft_strncmp(*argv, "unset", 6))
		ft_unset(argv);
	else
		ft_execve(argv);
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
	ft_signal();
	while (1)
	{
		command_line = readline("blackhole-shell$ ");
		exit_eof(command_line);
		if (*command_line)
			add_history(command_line);
		init_manger(command_line);
		ast = syntax_analyzer();
		test_ast(ast);
		free(command_line);
	}
	return (0);
}
