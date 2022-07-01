/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_simple_command.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 04:58:37 by nkim              #+#    #+#             */
/*   Updated: 2022/07/01 16:08:13 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
   init_simple_command
   initialize_simple_command structure
   case 1) simple_command not allocated
   case 2) simple_command already allocated
*/
static char	**init_simple_command(t_simple_command **simple_command, int *ac)
{
	char	**argv;

	if (*simple_command == NULL)
	{
		*simple_command = bs_calloc(1, sizeof(t_simple_command));
		(*simple_command)->exec_path = get_combined_word();
		argv = bs_calloc((*ac) + 2, sizeof(char *));
		argv[(*ac)++] = (*simple_command)->exec_path;
	}
	else
	{
		argv = (*simple_command)->argv;
		while (argv[(*ac)])
			(*ac)++;
	}
	return (argv);
}

/*
   syntax_simple_command
   ac: argv count
*/
int	syntax_simple_command(t_simple_command **simple_command)
{
	int		ac;
	char	**argv;

	ac = 0;
	argv = init_simple_command(simple_command, &ac);
	while (fetch_token(GET).type == T_WORD)
	{
		argv = ft_ptrrealloc(argv, ac, ac + 2);
		argv[ac++] = get_combined_word();
	}
	argv[ac] = NULL;
	(*simple_command)->argv = argv;
	return (SUCCESS_FLAG);
}
