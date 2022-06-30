/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 21:17:33 by nkim              #+#    #+#             */
/*   Updated: 2022/06/30 12:41:00 by hannkim          ###   ########.fr       */
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

void	reset_minishell(t_ast *ast, int std_fd[3])
{
	free_ast(ast);
	free(g_manager.command_line);
	reset_std_fd(std_fd);
}

void	init_minishell(int argc, char **argv, char **envp, int std_fd[3])
{
	if (argc > 1)
		throw_error_exit(argv[1], strerror(ENOENT), EXIT_ENOENT);
	write(STDOUT_FILENO, SPLASHTEXT, 1934);
	backup_std_fd(std_fd);
	while (*envp)
	{
		add_env(get_env_name(*envp), get_env_value(*envp));
		envp++;
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		std_fd[3];
	char	*command_line;
	t_ast	*ast;

	init_minishell(argc, argv, envp, std_fd);
	while (TRUE)
	{
		init_signal();
		command_line = readline(PS1);
		ft_exit_eof(command_line);
		if (*command_line)
		{
			add_history(command_line);
			init_manger(command_line);
			ast = syntax_analyzer();
			if (g_manager.exit_code == EXIT_SUCCESS)
				exec_ast(ast);
			reset_minishell(ast, std_fd);
		}
		free(command_line);
	}
	return (EXIT_SUCCESS);
}
