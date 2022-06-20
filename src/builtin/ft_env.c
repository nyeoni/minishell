/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 18:20:19 by hannkim           #+#    #+#             */
/*   Updated: 2022/06/20 16:44:36 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(void)
{
	t_env	*ptr;

	ptr = g_manager.env;
	while (ptr)
	{
		ft_putstr_fd(ptr->name, STDOUT_FILENO);
		write(STDOUT_FILENO, "=", 1);
		ft_putstr_fd(ptr->value, STDOUT_FILENO);
		write(STDOUT_FILENO, "\n", 1);
		ptr = ptr->next;
	}
}
