/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 21:17:33 by nkim              #+#    #+#             */
/*   Updated: 2022/06/20 16:29:44 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_manager	g_manager;

void	init_manger(char *command_line)
{
	g_manager.envp = 0;
	g_manager.command_line = command_line;
	g_manager.rc = 0;
}

t_list	*env;

void	initiate_env(char **envp)
{
	while (*envp)
	{
		ft_lstadd_back(&env, ft_lstnew(*envp));
		envp++;
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
}

int	main (int argc, char **argv, char **envp)
{
	char	*prompt;
	char	**arg;
	t_ast	*AST;

	if (argc > 1)
	{
		printf("ERROR : %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	initiate_env(envp);
	
	while (1)
	{
		prompt = readline("blackhole-shell$ ");
		init_manger(prompt);
		// test tokenization
		// tmp = get_token();
		// while (tmp.type != T_NULL)
		// {
		// 	printf("%d: %s\n", tmp.type, tmp.value);
		// 	tmp = get_token();
		// }
		// test parsing
		AST = syntax_analyzer();
		// printf("%s\n", command_line);

		arg = ft_split(prompt, ' ');
		execute_cmd(arg);
		// parse
		// execute command : builtin or general
		free(prompt);
	}
	return (0);
}
