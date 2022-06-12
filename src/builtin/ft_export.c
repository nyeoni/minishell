/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 18:20:31 by hannkim           #+#    #+#             */
/*   Updated: 2022/06/12 14:01:46 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

extern t_list	*env;

int		is_valid_identifier(char *identifier)
{
	char	*ptr;

	ptr = identifier;
	// 알파벳으로 시작하지 않으면 에러처리
	if ((*identifier < 'a' || *identifier > 'z') &&\
			(*identifier < 'A' || *identifier > 'Z'))
		return (EXIT_FAILURE);
	while (*ptr != '=')
	{
		if (*ptr != '_' || (*ptr >= '0' && *ptr <= '9'))
			return (EXIT_FAILURE);
		ptr++;
	}
	return (EXIT_SUCCESS);
}

void	ft_export(char **argv)
{
	t_list	*ptr;

	if (!argv[1])		// export
	{
//		ft_env();
		return ;
	}
	argv++;
	while (*argv)
	{
		if (ft_strchr(*argv, '='))
		{
			if (is_valid_identifier(*argv) == EXIT_FAILURE)
				throw_error_env("export", *argv);
			else
			{
				ptr = get_env(*argv);
				if (ptr)	// 해당 변수명이 이미 만들어져 있는 경우 -> 덮어 쓰기
					ptr->content = *argv;
				else
					ft_lstadd_back(&env, ft_lstnew(*argv));
			}
		}
		argv++;
	}
}
