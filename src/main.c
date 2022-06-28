/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 21:17:33 by nkim              #+#    #+#             */
/*   Updated: 2022/06/28 20:26:34 by nkim             ###   ########.fr       */
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
	int		std_fd[3];
	char	*command_line;
	t_ast	*ast;

	if (argc > 1)
		throw_error_exit(argv[1], strerror(ENOENT), EXIT_ENOENT);
	init_env(envp);
	backup_std_fd(std_fd);
	while (1)
	{
		check_signal();
		command_line = readline(PS1);
		ft_exit_eof(command_line);
		if (*command_line)
			add_history(command_line);
		init_manger(command_line);
		ast = syntax_analyzer();
		if (g_manager.exit_code == EXIT_SUCCESS)
			exec_ast(ast);
		free(command_line);
		reset_std_fd(std_fd);
	}
	return (0);
}
