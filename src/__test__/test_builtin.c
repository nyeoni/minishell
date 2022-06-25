/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 19:47:51 by hannkim           #+#    #+#             */
/*   Updated: 2022/06/25 19:48:22 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* main insert below readline() */
void	test_builtin(void)
{
	char	**arg;
	char	**ptr;
	char	*tmp;

	arg = ft_split(g_manager.command_line, ' ');
	exec_builtin(arg);
	ptr = arg;
	while (*ptr)
	{
		tmp = *ptr;
		ptr++;
		free(tmp);
	}
	free(arg);
}
