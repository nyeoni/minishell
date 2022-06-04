/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 21:17:33 by nkim              #+#    #+#             */
/*   Updated: 2022/06/04 19:36:41 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_manager manager;

t_ast *parse_line(char *command_line)
{
	t_ast *AST;
	char *token;

	token = get_token(command_line);
	if (token == T_NULL) return 0; // TODO: prompt 가 newLine 받는 상태로
	AST = ft_calloc(1, sizeof(t_ast));
	
	return AST;
}

int	main (int argc, char **argv, char **envp)
{
	char *command_line;
	// TODO: 나중에는 ; 을 기준으로 ASTs 를 만들어야할 예정
	t_ast *AST;

	while (1)
	{
		command_line = readline("Enter a line : ");
		AST = parse_line(command_line);

		printf("%s\n", command_line);
	}
	return 0;
}
