/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_option.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 20:17:21 by hannkim           #+#    #+#             */
/*   Updated: 2022/07/01 16:28:51 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

/*
	option O -> exit_code = EXIT_FAILURE
	option X -> exit_code = EXIT_SUCCESS
*/
int	check_option(char *argv)
{
	int	exit_code;

	exit_code = EXIT_SUCCESS;
	if (*argv == '-')
		exit_code = EXIT_FAILURE;
	return (exit_code);
}
