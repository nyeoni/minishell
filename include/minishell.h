/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 18:36:42 by nkim              #+#    #+#             */
/*   Updated: 2022/06/20 16:24:18 by hannkim          ###   ########.fr       */
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

typedef struct s_manager
{
	t_list			**envp;
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
void	ft_echo(char **argv);
void	ft_cd(char **argv);
void	ft_pwd(char **argv);
void	ft_env(void);

/* ERROR */
void	throw_error(char *cmd, char *argv, char *err);

#endif
