/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 03:31:38 by nkim              #+#    #+#             */
/*   Updated: 2022/06/24 03:31:53 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin(char *exec_path)
{
	if (!ft_strncmp(exec_path, "cd", 3))
		return (TRUE);
	else if (!ft_strncmp(exec_path, "echo", 5))
		return (TRUE);
	else if (!ft_strncmp(exec_path, "pwd", 4))
		return (TRUE);
	else if (!ft_strncmp(exec_path, "env", 4))
		return (TRUE);
	else if (!ft_strncmp(exec_path, "exit", 5))
		return (TRUE);
	else if (!ft_strncmp(exec_path, "export", 7))
		return (TRUE);
	else if (!ft_strncmp(exec_path, "unset", 6))
		return (TRUE);
	else
		return (FALSE);
}
