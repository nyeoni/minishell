/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:14:23 by nkim              #+#    #+#             */
/*   Updated: 2022/06/04 16:39:35 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

# include "token.h"

# define AST_PIPELINE		0
# define AST_COMMAND		1
# define AST_SIMPLE_COMMAND	2
# define AST_REDIRECTS		3
# define AST_IO_REDIRECT	4

typedef struct s_command		t_command;
typedef struct s_simple_command	t_simple_command;
typedef struct s_redirects		t_redirects;
typedef struct s_io_redirect	t_io_redirect;

/* ast tree generate node */
typedef struct s_ast
{
	int							type;
	void						*data;
	struct s_ast				*left;
	struct s_ast				*right;
}								t_ast;

/* <pipe_line>   -> <command> { '|' <pipe_line> } */
typedef struct s_pipe_line
{
	t_command					*command;
	struct s_pipe				*pipe_line;
}								t_pipe_line;

/* <command> -> [ <simple_command> ][ <redirects> ]
   1 0
   0 1
   1 1
   여기서 나중에 파싱트리 만들때 순서 바꾸는 거 잊지 말것
*/
typedef struct s_command
{
	struct s_simple_command		*simple_command;
	struct s_redirects			*redirects;
}								t_command;

/* <simple_command> -> <exec_path> { <argv> } */
typedef struct s_simple_command
{
	WORD						exec_path;
	WORD						argv;
}								t_simple_command;

/* <redirects> -> <io_redirect> { <redirects> } */
typedef struct s_redirects
{
	struct s_io_redirect		*io_redirect;
	struct s_redirects			*redirects;
}								t_redirects;

/* <io_redirect> -> <redirect_op> <file_path> */
typedef struct s_io_redirect
{
	REDIRECT_OP					redirect_op;
	WORD						file_path;
}								t_io_redirect;

#endif
