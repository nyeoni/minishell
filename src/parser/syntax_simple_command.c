/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_simple_command.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 04:58:37 by nkim              #+#    #+#             */
/*   Updated: 2022/06/20 05:19:52 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	syntax_simple_command(t_simple_command *simple_command)
{
	char *tmp;

	printf("===simple_command===\n");
	simple_command = ft_calloc(1, sizeof(t_simple_command));
	simple_command->exec_path = match(T_WORD);
	printf("s1: %s\n", simple_command->exec_path);
	if (fetch_token(GET).type == T_WORD)
	{
		tmp = ft_strjoin(simple_command->exec_path, " ");
		simple_command->argv =
			ft_strjoin(tmp, match(T_WORD));
		free(tmp);
	}
	printf("s2: %s\n", simple_command->argv);
	printf("======\n");
}