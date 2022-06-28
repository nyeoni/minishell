/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 03:31:38 by nkim              #+#    #+#             */
/*   Updated: 2022/06/29 02:40:51 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin(char *exec_path)
{
	if (!ft_strcmp(exec_path, "cd"))
		return (TRUE);
	else if (!ft_strcmp(exec_path, "echo"))
		return (TRUE);
	else if (!ft_strcmp(exec_path, "pwd"))
		return (TRUE);
	else if (!ft_strcmp(exec_path, "env"))
		return (TRUE);
	else if (!ft_strcmp(exec_path, "exit"))
		return (TRUE);
	else if (!ft_strcmp(exec_path, "export"))
		return (TRUE);
	else if (!ft_strcmp(exec_path, "unset"))
		return (TRUE);
	else
		return (FALSE);
}
