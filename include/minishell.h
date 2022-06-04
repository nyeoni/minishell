/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 18:36:42 by nkim              #+#    #+#             */
/*   Updated: 2022/06/04 18:49:36 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>

#include "../libft/libft.h"
#include "ast.h"

typedef struct s_manager
{
  t_list **envp;
  t_list **commands;
} t_manager;