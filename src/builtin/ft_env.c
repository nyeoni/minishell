/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 18:20:19 by hannkim           #+#    #+#             */
/*   Updated: 2022/06/04 18:47:18 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

extern t_list *env;

void	ft_env(void)
{
	t_list *ptr;

	ptr = env;
	while (ptr)
	{
		ft_putstr_fd(ptr->content, STDOUT_FILENO);
		ft_putstr_fd("\n", STDOUT_FILENO);
		ptr = ptr->next;
	}
}
