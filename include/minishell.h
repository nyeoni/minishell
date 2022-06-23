/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:35:25 by hannkim           #+#    #+#             */
/*   Updated: 2022/06/24 02:59:04 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "ast.h"
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
void				syntax_pipe_line(t_ast **ast_pipe_line);
void				syntax_command(t_ast **ast_command);
void				syntax_redirects(t_ast **ast_redirects);
void				syntax_simple_command(t_simple_command **simple_command);
void				syntax_io_redirect(t_io_redirect **io_redirect);
char				*syntax_word(char *token);
char				*syntax_heredoc_word(char *token);
char				*get_combined_word(void);
char				*get_combined_heredoc_word(void);

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

/* ENV */
t_env				*get_env(char *identifier);
int					is_valid_identifier(char *identifier);
char				*get_name(char *argv);
char				*get_value(char *argv);
void				add_env(char *name, char *value);
void				remove_env(t_env *target);

/* EXEC */
void				ft_execve(char **argv);
void				exec_ast(t_ast *ast);

/* SIGNAL */
void				exit_eof(char *command_line);
void				ft_signal(void);

#endif
