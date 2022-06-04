/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 14:40:53 by nkim              #+#    #+#             */
/*   Updated: 2022/06/04 16:33:35 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define T_NULL 0
# define T_WORD 1 /* WORD -> word | "word" | 'word' */
# define T_PIPE 2
# define T_REDIRECT 3
# define T_DOUBLE_QUOTES 4
# define T_SINGLE_QUOTES 5
typedef struct s_token {
	int	type;
	char	*str;
}	t_token;

/* TODO: 이 부분 다시 생각해보기 */
typedef enum e_redirect_op {
	IN,
	OUT,
	HEREDOC,
	APPEND
} t_redirect_op;
typedef char *WORD;
typedef t_redirect_op REDIRECT_OP;
