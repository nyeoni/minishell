/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:14:23 by nkim              #+#    #+#             */
/*   Updated: 2022/06/22 01:22:43 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

# include "token.h"

typedef struct s_command		t_command;
typedef struct s_simple_command	t_simple_command;
typedef struct s_redirects		t_redirects;
typedef struct s_io_redirect	t_io_redirect;

typedef enum e_ast_type
{
	AST_NULL,
	AST_PIPELINE,
	AST_COMMAND,
	AST_REDIRECTS
}				t_ast_type;

/* ast tree generate node
   t_ast can be...
   pipe_line -> 0
   command   -> 1
   redirects -> 2
*/
typedef struct s_ast
{
	t_ast_type					type;
	void						*data;
}								t_ast;

/* <pipe_line>   -> <command> { '|' <pipe_line> } */
typedef struct s_pipe_line
{
	t_ast						*command;
	t_ast						*pipe_line;
}								t_pipe_line;

/* <command> -> [ <simple_command> ][ <redirects> ]
   1 0
   0 1
   1 1
*/
typedef struct s_command
{
	struct s_simple_command		*simple_command;
	t_ast						*redirects;
}								t_command;

/* <simple_command> -> <exec_path> { <argv> } */
typedef struct s_simple_command
{
	char						*exec_path;
	char						**argv;
}								t_simple_command;

/* <redirects> -> <io_redirect> { <redirects> } */
typedef struct s_redirects
{
	struct s_io_redirect		*io_redirect;
	t_ast						*redirects;
}								t_redirects;

/* <io_redirect> -> <redirect_op> <file_path> */
typedef struct s_io_redirect
{
	char						*redirect_op;
	char						*file_path;
}								t_io_redirect;

#endif
