/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 18:20:26 by hannkim           #+#    #+#             */
/*   Updated: 2022/06/04 21:54:29 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_exit(void)
{
	ft_putstr_fd("exit\n", STDOUT_FILENO);
	exit(EXIT_SUCCESS);
}
