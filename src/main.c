/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 21:17:33 by nkim              #+#    #+#             */
/*   Updated: 2022/06/12 14:21:05 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_manager	manager;

void		command()
{
	char	*token;

}
void		pipe_line(t_ast *AST)
{
	// command();
	// token = get_token();
}

t_ast		*parse_line(char *command_line)
{
	t_ast	*AST;
	char	*token;

	AST = ft_calloc(1, sizeof(t_ast));
	token = get_token();
	// TODO: prompt 가 newLine 받는 상태로
	if (token == T_NULL)
		return (t_ast *)NULL_LINE;
	AST->type = AST_PIPELINE;
	AST->data = ft_calloc(1, sizeof(t_pipe_line));
	pipe_line(AST);
	return (AST);
}

int			init_manger(char *command_line)
{
	manager.envp = 0;
	manager.command_line = command_line;
	manager.command_len = ft_strlen(command_line);
	manager.rc = 0;
}

int			main(int argc, char **argv, char **envp)
{
	char	*command_line;
	char	*tmp;
	t_ast	*AST;

	// TODO: 나중에는 ; 을 기준으로 ASTs 를 만들어야할 예정
	while (1)
	{
		command_line = readline("Enter a line : ");
		init_manger(command_line);
		while ((tmp = get_token()))
			printf("token: %s\n", tmp);
		// AST = parse_line(command_line);
		printf("%s\n", command_line);
	}
	return (0);
}
