/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 18:20:13 by hannkim           #+#    #+#             */
/*   Updated: 2022/06/04 20:16:13 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_echo(char **argv)
{
	int	option;
	int	i;

	option = 0;
	i = 1;
	if (!ft_strncmp(argv[1], "-n", 3))
	{
		option = 1;
		i++;
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

//int main()
//{
////	char *str = "echo   -n   \"hello im hannh         \"";
//	char *str = "echo     -n  ";
//	char **argv;
//
//	argv = ft_split(str, ' ');
//	echo(argv);
//
//	return (0);
//}
