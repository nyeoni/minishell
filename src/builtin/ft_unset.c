/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 23:58:57 by hannkim           #+#    #+#             */
/*   Updated: 2022/06/24 16:46:17 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_unset(char **argv)
{
	t_env	*target;

	if (!argv[1])
		return ;
	argv++;
	while (*argv)
	{
		if (ft_strchr(*argv, '='))
			throw_error_env("unset", *argv);
		else if (valid_env_name(*argv) == EXIT_FAILURE)
			throw_error_env("unset", *argv);
		else
		{
			target = get_env(*argv);
			if (target)
			{
				remove_env(target);
			}
		}
		argv++;
	}
}
