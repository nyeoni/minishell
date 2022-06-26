/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:23:16 by hannkim           #+#    #+#             */
/*   Updated: 2022/06/26 15:32:20 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// TODO : $? -> exit_code 반환
t_env	*get_env(char *identifier)
{
	t_env				*ptr;
	unsigned int		len;

	ptr = g_manager.env;
	len = ft_strlen(identifier);
	while (ptr)
	{
		if (ft_strlen(ptr->name) == len && \
				ft_strncmp(identifier, ptr->name, len) == 0)
			return (ptr);
		ptr = ptr->next;
	}
	return (NULL);
}

int	valid_env_name(char *identifier)
{
	char	*ptr;

	ptr = identifier;
	if ((*identifier < 'a' || *identifier > 'z') && \
			(*identifier < 'A' || *identifier > 'Z'))
		return (EXIT_FAILURE);
	while (*ptr && *ptr != '=')
	{
		if (((*ptr < 'a' || *ptr > 'z') && (*ptr < 'A' || *ptr > 'Z')) && \
			(*ptr != '_') && \
					((*ptr >= '0' && *ptr <= '9')))
			return (EXIT_FAILURE);
		ptr++;
	}
	return (EXIT_SUCCESS);
}

char	*get_env_name(char *argv)
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

char	*get_env_value(char *argv)
{
	char	*value;
	char	*ptr;
	int		len;

	ptr = ft_strchr(argv, '=');
	ptr++;
	len = ft_strlen(ptr) + 1;
	value = (char *)ft_calloc(len, sizeof(char));
	if (!value)
		exit(EXIT_FAILURE);
	ft_strlcpy(value, ptr, len);
	return (value);
}

void	free_env(void)
{
	t_env	*tmp;

	while (g_manager.env)
	{
		tmp = g_manager.env;
		g_manager.env = g_manager.env->next;
		if (tmp->name)
			free(tmp->name);
		if (tmp->value)
			free(tmp->value);
		free(tmp);
	}
}
