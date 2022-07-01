/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throw_error_usage.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 19:58:57 by hannkim           #+#    #+#             */
/*   Updated: 2022/07/01 16:15:40 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

/*
	print usage
	bash: "cmd": --: invalid option
	"cmd": usage: "cmd" no option
*/
int	throw_error_usage(char *cmd, char *argv)
{
	ft_putstr_fd("blackhole-shell: ", STDOUT_FILENO);
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
