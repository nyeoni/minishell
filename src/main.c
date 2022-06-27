/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 21:17:33 by nkim              #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/06/27 17:59:49 by hannkim          ###   ########.fr       */
=======
/*   Updated: 2022/06/27 17:08:54 by nkim             ###   ########.fr       */
>>>>>>> ea81541 (feat: Update exit_code special character parsing)
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
	while (1)
	{
		check_signal();
		command_line = readline(PS1);
		printf("after cmd line : %s\n", command_line);
		ft_exit_eof(command_line);
		if (*command_line)
			add_history(command_line);
		init_manger(command_line);
		ast = syntax_analyzer();
		exec_ast(ast);
		free(command_line);
	}
	return (0);
}
