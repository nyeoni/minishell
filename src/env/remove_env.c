/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 16:39:29 by nkim              #+#    #+#             */
/*   Updated: 2022/06/29 16:39:39 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	remove_env(t_env *target)
{
	t_env	*prev;

	prev = g_manager.env;
	while (prev->next != target)
		prev = prev->next;
	prev->next = target->next;
	free(target->name);
	free(target->value);
	free(target);
}
