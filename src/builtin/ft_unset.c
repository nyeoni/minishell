/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 18:20:42 by hannkim           #+#    #+#             */
/*   Updated: 2022/06/05 17:09:06 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

extern t_list	*env;

void	ft_unset(char **argv)
{
	argv++;
	while (*argv)
	{
		if (**argv == '=')
			throw_error_env("unset", *argv);
		else if (ft_strchr(*argv, '='))
//			ft_lstadd_back(&env, ft_lstnew(*argv));
		argv++;
	}
}
