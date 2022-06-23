/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 03:35:25 by nkim              #+#    #+#             */
/*   Updated: 2022/06/24 03:36:50 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "ast.h"

typedef enum e_fetch_type
{
	GET,
	UPDATE
}			t_fetch_type;

t_token		fetch_token(t_fetch_type type);
void		lexical_analyzer(t_token *token, char **begin, char **end);
t_ast		*syntax_analyzer(void);
char		*match(t_type type);
void		syntax_pipe_line(t_ast **ast_pipe_line);
void		syntax_command(t_ast **ast_command);
void		syntax_redirects(t_ast **ast_redirects);
void		syntax_simple_command(t_simple_command **simple_command);
void		syntax_io_redirect(t_io_redirect **io_redirect);
char		*syntax_word(char *token);
char		*syntax_heredoc_word(char *token);
char		*get_combined_word(void);
char		*get_combined_heredoc_word(void);

#endif