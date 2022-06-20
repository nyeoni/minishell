/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 21:10:50 by hannkim           #+#    #+#             */
/*   Updated: 2022/06/20 16:45:18 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_env(char *name, char *value)
{
	t_env	*ptr;
	t_env	*new;

	ptr = g_manager.env;
	new = (t_env *)ft_calloc(1, sizeof(t_env));
	if (!new)
		exit(EXIT_FAILURE);
	new->name = name;
	new->value = value;
	new->next = NULL;
	if (!g_manager.env)
	{
		g_manager.env = new;
		return ;
	}
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = new;
}

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
