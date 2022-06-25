/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 14:40:53 by nkim              #+#    #+#             */
/*   Updated: 2022/06/25 18:32:10 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

typedef enum e_type
{
	T_NULL,
	T_WORD,
	T_REDIRECT,
	T_PIPE
}				t_type;

typedef struct s_token
{
	t_type		type;
	char		*value;
}				t_token;

typedef enum e_unit
{
	U_IN = '<',
	U_OUT = '>',
	U_PIPE = '|',
	U_DOUBLE_QUOTES = '\"',
	U_SINGLE_QUOTES = '\'',
	U_BACK_SLASH	= '\\'
}				t_unit;

typedef enum e_redirect_op
{
	R_IN,
	R_OUT,
	R_HEREDOC,
	R_APPEND
}				t_redirect_op;

#endif