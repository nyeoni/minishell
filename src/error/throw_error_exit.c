/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throw_error_exit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 02:44:26 by nkim              #+#    #+#             */
/*   Updated: 2022/07/01 16:15:25 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

int	throw_error_exit(char *cmd, char *err, int exit_code)
{
	g_manager.exit_code = exit_code;
	throw_error(cmd, NULL, err);
	exit(g_manager.exit_code);
	return (EXIT_FAILURE);
}
