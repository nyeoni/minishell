/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bs_exit_eof.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:23:11 by hannkim           #+#    #+#             */
/*   Updated: 2022/06/30 18:12:40 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* EOF : ctrl + d */
void	bs_exit_eof(char	*command_line)
{
	if (!command_line)
	{
		ft_putstr_fd("exit\n", STDERR_FILENO);
		exit(EXIT_SUCCESS);
	}
}
