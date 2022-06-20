/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 21:10:50 by hannkim           #+#    #+#             */
/*   Updated: 2022/06/20 00:07:05 by hannkim          ###   ########.fr       */
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

t_env	*get_env(char *identifier)
{
	t_env				*ptr;
	unsigned int		len;

	ptr = manager.env;
	len = ft_strlen(identifier);
	while (ptr)
	{
		if (ft_strlen(ptr->name) == len && ft_strncmp(identifier, ptr->name, len) == 0)
			return (ptr);
		ptr = ptr->next;
	}
	return (NULL);
}

void	remove_env(t_env *target)
{
	t_env *prev;

	prev = manager.env;
	while (prev->next != target)
		prev = prev->next;
	prev->next = target->next;
	free(target->name);
	free(target->value);
	free(target);
}

int		is_valid_identifier(char *identifier)
{
	char	*ptr;

	ptr = identifier;
	// 알파벳으로 시작하지 않으면 에러처리
	if ((*identifier < 'a' || *identifier > 'z') &&\
			(*identifier < 'A' || *identifier > 'Z'))
		return (EXIT_FAILURE);
	while (*ptr && *ptr != '=')
	{
		if (((*ptr < 'a' || *ptr > 'z') && (*ptr < 'A' || *ptr > 'Z')) &&\
			(*ptr != '_') && \
					((*ptr >= '0' && *ptr <= '9')))
			return (EXIT_FAILURE);
		ptr++;
	}
	return (EXIT_SUCCESS);
}

char	*get_name(char *argv)
{
	char	*name;
	int		len;

	len = ft_strchr(argv, '=') - argv + 1;
	name = (char *)ft_calloc(len, sizeof(char));
	if (!name)
		exit(EXIT_FAILURE);
	ft_strlcpy(name, argv, len);
	return (name);
}

char	*get_value(char *argv)
{
	char	*value;
	char	*ptr;
	int		len;

	ptr = ft_strchr(argv, '=');
	ptr++;		// '=' 다음 문자 가리키도록
	len = ft_strlen(ptr) + 1;
	value = (char *)ft_calloc(len, sizeof(char));
	if (!value)
		exit(EXIT_FAILURE);
	ft_strlcpy(value, ptr, len);
	return (value);
}
