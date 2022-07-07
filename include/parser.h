/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 03:35:25 by nkim              #+#    #+#             */
/*   Updated: 2022/07/07 13:40:07 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "ast.h"
# include "libft.h"
# include "minishell.h"
# include <stdlib.h>
# include <unistd.h>

typedef enum e_fetch_type
{
	GET,
	UPDATE
}		t_fetch_type;

t_token	fetch_token(t_fetch_type type);
int		lexical_analyzer(t_token *token, char **begin, char **end);
t_ast	*syntax_analyzer(void);
char	*match(t_type type);
int		syntax_pipe_line(t_ast **ast_pipe_line);
int		syntax_command(t_ast **ast_command);
int		syntax_redirects(t_ast **ast_redirects);
int		syntax_simple_command(t_simple_command **simple_command);
int		syntax_io_redirect(t_io_redirect **io_redirect);
char	*syntax_word(char *token);
char	*syntax_heredoc_word(char *token);
char	*get_combined_word(void);
char	*get_combined_heredoc_word(void);
char	*replace_env(char *token);

void	free_ast(t_ast *ast);
void	free_simple_command(t_simple_command *simple_command);
void	free_io_redirect(t_io_redirect *io_redirect);

#endif