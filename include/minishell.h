/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 18:36:42 by nkim              #+#    #+#             */
/*   Updated: 2022/06/20 00:44:35 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>

#include "../libft/libft.h"
#include "ast.h"

# define NULL_LINE 0;
# define ERROR_FLAG -1
# define SUCCESS_FLAG 0

typedef struct s_manager
{
  t_list **envp;
  char *command_line;
  int command_len;
  int rc; // read counter
} t_manager;

typedef enum e_fetch_type
{
	GET,
	UPDATE
} t_fetch_type;

extern t_manager manager;

/* UTILS */
int	ft_isspace(int c);

/* PARSER */
t_token get_token();