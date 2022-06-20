/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 18:36:42 by nkim              #+#    #+#             */
/*   Updated: 2022/06/20 05:00:41 by nkim             ###   ########.fr       */
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
  char *command_line; // 이건 나중에 처리할 수 있는지 고민해보기
  int rc; // read counter 이것도 나중에 static 처리하기
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
t_token	fetch_token(t_fetch_type type);
void	lexical_analyzer(t_token *token, char **begin, char **end);
t_ast	*syntax_analyzer();
char	*match(t_type type);
void	syntax_pipe_line(t_ast *ast_pipe_line);
void	syntax_command(t_ast *ast_command);
void	syntax_simple_command(t_simple_command *simple_command);
void	syntax_redirects(t_ast *ast_redirects);
void	syntax_io_redirect(t_io_redirect *io_redirect);