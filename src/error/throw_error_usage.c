/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throw_error_usage.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 19:58:57 by hannkim           #+#    #+#             */
/*   Updated: 2022/06/25 23:20:25 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	print usage
	bash: "cmd": --: invalid option 
	"cmd": usage: "cmd" no option
*/
int	throw_error_usage(char *cmd, char *argv)
{
	ft_putstr_fd("bash: ", STDOUT_FILENO);
	ft_putstr_fd(cmd, STDOUT_FILENO);
	ft_putstr_fd(": ", STDOUT_FILENO);
	write(STDOUT_FILENO, argv, 2);
	ft_putstr_fd(": invalid option\n", STDOUT_FILENO);
	ft_putstr_fd(cmd, STDOUT_FILENO);
	ft_putstr_fd(": usage: ", STDOUT_FILENO);
	ft_putstr_fd(cmd, STDOUT_FILENO);
	ft_putstr_fd("\n", STDOUT_FILENO);
	return (EXIT_FAILURE);
}