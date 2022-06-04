/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 18:20:37 by hannkim           #+#    #+#             */
/*   Updated: 2022/06/04 20:22:37 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_pwd(char **argv)
{
	char	*cwd;

	if (!argv[1])
	{
		throw_error("pwd", NULL, strerror(errno));
		return ;
	}
	cwd = getcwd(NULL, 0);
	if (!cwd)
	{
		throw_error("pwd", NULL, strerror(errno));
		return ;
	}
	ft_putstr_fd(cwd, STDOUT_FILENO);
	free(cwd);
}
