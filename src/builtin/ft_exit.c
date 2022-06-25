/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 18:20:26 by hannkim           #+#    #+#             */
/*   Updated: 2022/06/25 22:29:26 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// TODO : exit code 계산
void	ft_exit(char **argv)
{
	ft_putstr_fd("exit\n", STDOUT_FILENO);
	free_env();
	exit(EXIT_SUCCESS);
}
