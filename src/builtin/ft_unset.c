/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 18:20:42 by hannkim           #+#    #+#             */
/*   Updated: 2022/06/20 17:10:40 by hannkim          ###   ########.fr       */
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
		else if (is_valid_identifier(*argv) == EXIT_FAILURE)
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
