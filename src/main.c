/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 21:17:33 by nkim              #+#    #+#             */
/*   Updated: 2022/06/20 14:30:57 by nkim             ###   ########.fr       */
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

int		main(int argc, char **argv, char **envp)
{
	char	*command_line;
	t_token tmp;
	t_ast	*AST;

	while (1)
	{
		command_line = readline("Enter a line : ");
		init_manger(command_line);

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
	}
	return (0);
}
