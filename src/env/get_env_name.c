/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_name.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 16:37:30 by nkim              #+#    #+#             */
/*   Updated: 2022/07/01 16:45:27 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

char	*get_env_name(char *argv)
{
	char	*name;
	size_t	len;

	if (!ft_strchr(argv, '='))
		len = ft_strlen(argv) + 1;
	else
		len = ft_strchr(argv, '=') - argv + 1;
	name = (char *)bs_calloc(len, sizeof(char));
	if (!name)
		exit(EXIT_FAILURE);
	ft_strlcpy(name, argv, len);
	return (name);
}
