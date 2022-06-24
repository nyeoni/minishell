/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 18:20:13 by hannkim           #+#    #+#             */
/*   Updated: 2022/06/24 13:55:10 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(char **argv)
{
	int	option;
	int	i;
	int	j;

	option = 0;
	i = 1;
	j = 2;
	if (!ft_strncmp(argv[1], "-n", 2))
	{
		while (argv[1][j] == 'n')
			j++;
		if (argv[1][j])
			option = 0;
		else
		{
			option = 1;
			i++;
		}
	}
	while (argv[i])
	{
		ft_putstr_fd(argv[i], STDOUT_FILENO);
		if (argv[i + 1])
			ft_putstr_fd(" ", STDOUT_FILENO);
		i++;
	}
	if (!option)
		ft_putstr_fd("\n", STDOUT_FILENO);
}
