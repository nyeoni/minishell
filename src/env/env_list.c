/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 21:10:50 by hannkim           #+#    #+#             */
/*   Updated: 2022/06/20 14:18:15 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	add_env(char *name, char *value)
{
	t_env	*ptr;
	t_env	*new;

	ptr = manager.env;
	new = (t_env *)ft_calloc(1, sizeof(t_env));
	if (!new)
		exit(EXIT_FAILURE);
	new->name = name;
	new->value = value;
	new->next = NULL;
	if (!manager.env)
	{
		manager.env = new;
		return ;
	}
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = new;
}

void	remove_env(t_env *target)
{
	t_env	*prev;

	prev = manager.env;
	while (prev->next != target)
		prev = prev->next;
	prev->next = target->next;
	free(target->name);
	free(target->value);
	free(target);
}
