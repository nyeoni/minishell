/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_simple_command.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 04:58:37 by nkim              #+#    #+#             */
/*   Updated: 2022/06/23 17:00:26 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
   syntax_simple_command
   ac: argv count
*/
void	syntax_simple_command(t_simple_command **simple_command)
{
	int		ac;
	char	**argv;

	ac = 0;
	if (*simple_command == NULL)
	{
		*simple_command = ft_calloc(1, sizeof(t_simple_command));
		(*simple_command)->exec_path = get_combined_word();
		argv = ft_calloc(ac + 2, sizeof(char *));
		argv[ac++] = (*simple_command)->exec_path;
	}
	else
	{
		argv = (*simple_command)->argv;
		while (argv[ac])
			ac++;
	}
	while (fetch_token(GET).type == T_WORD)
	{
		argv = ft_ptrrealloc(argv, ac, ac + 2);
		argv[ac++] = get_combined_word();
	}
	argv[ac] = NULL;
	(*simple_command)->argv = argv;
}
