/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_simple_command.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 22:11:30 by nkim              #+#    #+#             */
/*   Updated: 2022/06/30 19:14:28 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_simple_command(t_simple_command *simple_command)
{
	int	ac;

	ac = 0;
	while (simple_command->argv[ac])
		free(simple_command->argv[ac++]);
	free(simple_command->argv);
	free(simple_command);
}
