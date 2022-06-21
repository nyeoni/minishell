/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 18:36:42 by nkim              #+#    #+#             */
/*   Updated: 2022/06/20 19:00:22 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include "ast.h"
# include <readline/readline.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/errno.h>

# define NULL_LINE 0;
# define ERROR_FLAG -1
# define SUCCESS_FLAG 0

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

typedef enum e_fetch_type
{
	GET,
	UPDATE
}					t_fetch_type;

extern t_manager	g_manager;

/* UTILS */
int					ft_isspace(int c);
void				free_env(void);

/* PARSER */
t_token				fetch_token(t_fetch_type type);
void				lexical_analyzer(t_token *token, char **begin, char **end);
t_ast				*syntax_analyzer(void);
char				*match(t_type type);
void				syntax_pipe_line(t_ast *ast_pipe_line);
void				syntax_command(t_ast *ast_command);
void				syntax_simple_command(t_simple_command *simple_command);
void				syntax_redirects(t_ast *ast_redirects);
void				syntax_io_redirect(t_io_redirect *io_redirect);

/* BUILTIN */
void				execute_cmd(char **argv);
void				ft_echo(char **argv);
void				ft_cd(char **argv);
void				ft_pwd(char **argv);
void				ft_env(void);
void				ft_exit(void);
void				ft_export(char **argv);
void				ft_unset(char **argv);

/* ERROR */
void				throw_error(char *cmd, char *argv, char *err);
void				throw_error_env(char *cmd, char *argv);

/* ENV */
t_env				*get_env(char *identifier);
int					is_valid_identifier(char *identifier);
char				*get_name(char *argv);
char				*get_value(char *argv);
void				add_env(char *name, char *value);
void				remove_env(t_env *target);

#endif
