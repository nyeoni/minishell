/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 14:40:53 by nkim              #+#    #+#             */
/*   Updated: 2022/06/19 18:35:50 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// # define T_NULL 0
// # define T_WORD 1 /* WORD -> word | "word" | 'word' */
// # define T_PIPE 2
// # define T_REDIRECT 3
// # define T_DOUBLE_QUOTES "\""
// # define T_SINGLE_QUOTES 5
typedef char *WORD;

typedef enum e_type {
	T_NULL = 0,
	T_WORD = 1,
	T_HEREDOC = 2,
	T_APPEND = 3,
	T_IN = '<',
	T_OUT = '>',
	T_PIPE = '|',
	T_DOUBLE_QUOTES = '\"',
	T_SINGLE_QUOTES = '\''
} t_type;

typedef struct s_token {
	t_type	type;
	char	*value;
}	t_token;

// /* TODO: 이 부분 다시 생각해보기 */
typedef enum e_redirect_op {
	IN = '<',
	OUT = '\'',
	HEREDOC,
	APPEND
} t_redirect_op;
typedef t_redirect_op REDIRECT_OP;
