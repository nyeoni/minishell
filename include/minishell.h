/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:35:25 by hannkim           #+#    #+#             */
/*   Updated: 2022/06/24 23:18:01 by hannkim          ###   ########.fr       */
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

# define PS1 "\e[0;95mblackhole-shell$ \e[0m"
# define PS2 "> "

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
	int				exit_code;
}					t_manager;

extern t_manager	g_manager;

/* UTILS */
int					ft_isspace(int c);

/* PARSER */

/* BUILTIN */

/* ERROR */

/* ENV */
t_env				*get_env(char *identifier);
int					valid_env_name(char *identifier);
char				*get_env_name(char *argv);
char				*get_env_value(char *argv);
void				add_env(char *name, char *value);
void				remove_env(t_env *target);
void				free_env(void);

/* EXEC */
int					exec_builtin(char **argv);
int					exec_general(char **argv);
void				exec_ast(t_ast *ast);

/* SIGNAL */
void				ft_exit_eof(char *command_line);
void				check_signal(void);

#endif
