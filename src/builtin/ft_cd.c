/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 18:20:06 by hannkim           #+#    #+#             */
/*   Updated: 2022/06/24 23:15:02 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// TODO : throw_error -> return (EXIT_FAILURE);
int	ft_cd(char **argv)
{
	t_env	*ptr;
	char	*home;
	int		ret;

	if (!argv[1])
	{
		ptr = get_env("HOME");
		if (!ptr)
			throw_error("cd", NULL, strerror(errno));
		home = ptr->value;
		ret = chdir(home);
		if (ret < 0)
			throw_error("cd", NULL, strerror(errno));
		return (EXIT_SUCCESS);
	}
	ret = chdir(argv[1]);
	if (ret < 0)
	{
		throw_error("cd", argv[1], strerror(errno));
		printf("d\n");
		return (EXIT_SUCCESS);
	}
}
