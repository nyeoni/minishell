/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:11:37 by nkim              #+#    #+#             */
/*   Updated: 2022/06/20 19:29:22 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	get_token(void);

/* main insert below init_manager(command_line) */
void	test_token(void)
{
	t_token	token;

	token = get_token();
	while (token.type != T_NULL)
	{
		printf("%d: %s\n", token.type, token.value);
		free(token.value);
		token = get_token();
	}
	free(token.value);
}

/* main insert below readline() */
void	test_builtin(void)
{
	char	**arg;
	char	**ptr;
	char	*tmp;

	arg = ft_split(g_manager.command_line, ' ');
	execute_cmd(arg);
	ptr = arg;
	while (*ptr)
	{
		tmp = *ptr;
		ptr++;
		free(tmp);
	}
	free(arg);
}
