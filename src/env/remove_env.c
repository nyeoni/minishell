/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 16:39:29 by nkim              #+#    #+#             */
/*   Updated: 2022/07/01 16:17:44 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	remove_env(t_env *target)
{
	t_env	*tmp;

	tmp = g_manager.env;
	if (tmp == target)
		g_manager.env = tmp->next;
	else
	{
		while (tmp->next != target)
			tmp = tmp->next;
		tmp->next = target->next;
	}
	free(target->name);
	free(target->value);
	free(target);
}
