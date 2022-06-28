/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:35:25 by hannkim           #+#    #+#             */
/*   Updated: 2022/06/29 05:13:35 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/* CUSTOM HEADER FILE */
# include "../libft/libft.h"
# include "ast.h"
# include "builtin.h"
# include "error.h"
# include "exec.h"
# include "parser.h"
# include "redirect.h"
# include "subshell.h"

/* BUILTIN HEADER FILE */
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <string.h>
# include <sys/errno.h>
# include <sys/stat.h>

/* MECRO VARIABLES */
# define NULL_LINE 0;
# define ERROR_FLAG -1
# define SUCCESS_FLAG 0
# define TRUE 1
# define FALSE 0
# define READ 0
# define WRITE 1
# define ERROR 2

# define PS1 "\e[48;5;231m ✴ \e[0m\e[38;5;231m\e[48;5;63m\uE0B0\e[0m\e[0m\e[48;5;63m blackhole-shell \e[0m\e[38;5;63m\uE0B0 \e[0m"
# define PS2 "> "

/* STRUCUTER */
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
	int				quote_error;
	int				exit_code;
}					t_manager;

extern t_manager	g_manager;

/* MANAGER */
void				set_exit_code(int status);

/* UTILS */
int					ft_isspace(int c);

/* ENV */
t_env				*get_env(char *identifier);
int					valid_env_name(char *identifier);
char				*get_env_name(char *argv);
char				*get_env_value(char *argv);
void				add_env(char *name, char *value);
void				remove_env(t_env *target);
void				free_env(void);

/* SIGNAL */
void				ft_exit_eof(char *command_line);
void				check_signal(void);
void				reset_signal(void);

#endif
