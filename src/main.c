/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 21:17:33 by nkim              #+#    #+#             */
/*   Updated: 2022/06/20 17:28:52 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
}

int	main(int argc, char **argv, char **envp)
{
	char	*command_line;
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
		command_line = readline("blackhole-shell$ ");
		init_manger(command_line);
		AST = syntax_analyzer();
		execute_cmd(arg);
		free(command_line);
	}
	return (0);
}

// test tokenization
// tmp = get_token();
// while (tmp.type != T_NULL)
// {
// 	printf("%d: %s\n", tmp.type, tmp.value);
// 	tmp = get_token();
// }