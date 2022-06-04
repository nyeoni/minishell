/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 18:20:06 by hannkim           #+#    #+#             */
/*   Updated: 2022/06/04 20:23:01 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_cd(char **argv)
{
	char	*home;
	int		ret;

	if (!argv[1])
	{
		home = getenv("HOME");
		if (!home)
			throw_error("cd", NULL, strerror(errno));
		ret = chdir(home);		// home
		if (ret < 0)
			throw_error("cd", NULL, strerror(errno));
		return ;
	}
	ret = chdir(argv[1]);
	if (ret < 0)
	{
		throw_error("cd", argv[1], strerror(errno));
		printf("d\n");
		return ;
	}
}
