/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 23:58:28 by hannkim           #+#    #+#             */
/*   Updated: 2022/07/01 16:45:53 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

/*
	Usage: no argument, no option
	Argument or option -> exit_code = EXIT_FAILURE;
*/
int	ft_env(char **argv)
{
	t_env	*ptr;

	ptr = g_manager.env;
	if (*(argv + 1))
		return (throw_error_usage("env", *(argv + 1)));
	while (ptr)
	{
		if (ptr->value)
		{
			ft_putstr_fd(ptr->name, STDOUT_FILENO);
			write(STDOUT_FILENO, "=", 1);
			ft_putstr_fd(ptr->value, STDOUT_FILENO);
			write(STDOUT_FILENO, "\n", 1);
		}
		ptr = ptr->next;
	}
	return (EXIT_SUCCESS);
}
