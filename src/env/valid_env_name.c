/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_env_name.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 16:37:01 by nkim              #+#    #+#             */
/*   Updated: 2022/06/29 17:25:29 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	valid_env_name(char *identifier)
{
	char	*ptr;

	ptr = identifier;
	if ((*identifier < 'a' || *identifier > 'z') && (*identifier < 'A'
			|| *identifier > 'Z'))
		return (EXIT_FAILURE);
	while (*ptr && *ptr != '=')
	{
		if (((*ptr < 'a' || *ptr > 'z') && (*ptr < 'A' || *ptr > 'Z'))
			&& (*ptr != '_') && ((*ptr >= '0' && *ptr <= '9')))
			return (EXIT_FAILURE);
		ptr++;
	}
	return (EXIT_SUCCESS);
}
