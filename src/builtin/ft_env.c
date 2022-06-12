/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 18:20:19 by hannkim           #+#    #+#             */
/*   Updated: 2022/06/12 13:43:05 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

extern t_list *env;

t_list	*get_env(char *identifier)
{
	t_list	*ptr;
	int		len;

	ptr = env;
	len = ft_strchr(identifier, '=') - identifier;
	while (ptr)
	{
		if (ft_strncmp(identifier, ptr->content, len))
		{
			printf("len : %d\n", len);
			return (ptr);
		}
		ptr = ptr->next;
	}
	return (NULL);
}

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
