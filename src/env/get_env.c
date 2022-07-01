/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 16:36:32 by nkim              #+#    #+#             */
/*   Updated: 2022/07/01 16:17:50 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

t_env	*get_env(char *identifier)
{
	t_env			*ptr;
	unsigned int	len;

	ptr = g_manager.env;
	len = ft_strlen(identifier);
	while (ptr)
	{
		if (ft_strlen(ptr->name) == len && ft_strncmp(identifier, ptr->name,
				len) == 0)
			return (ptr);
		ptr = ptr->next;
	}
	return (NULL);
}
