/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:35:25 by hannkim           #+#    #+#             */
/*   Updated: 2022/06/24 16:23:20 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"

# include "ast.h"
# include "parser.h"
# include "builtin.h"
# include "error.h"

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <string.h>
# include <sys/errno.h>
# include <sys/stat.h>
# include <signal.h>

# define NULL_LINE 0;
# define ERROR_FLAG -1
# define SUCCESS_FLAG 0
# define TRUE 1
# define FALSE 0

typedef struct s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;
}					t_env;

typedef struct s_manager
{
	t_env			*env;
	char			*command_line;
	int				rc;
}					t_manager;

extern t_manager	g_manager;

/* UTILS */
int					ft_isspace(int c);
void				free_env(void);

/* PARSER */

/* BUILTIN */

/* ERROR */

/* ENV */
t_env				*get_env(char *identifier);
int					is_valid_identifier(char *identifier);
char				*get_name(char *argv);
char				*get_value(char *argv);
void				add_env(char *name, char *value);
void				remove_env(t_env *target);

/* EXEC */
void				exec_builtin(char **argv);
void				exec_general(char **argv);
void				exec_ast(t_ast *ast);

/* SIGNAL */
void				exit_eof(char *command_line);
void				ft_signal(void);

#endif
