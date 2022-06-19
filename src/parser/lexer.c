/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 14:11:59 by nkim              #+#    #+#             */
/*   Updated: 2022/06/19 23:45:28 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_word(t_token *token, char **begin, char **end)
{
	token->type = T_WORD;
	while (**end && (!ft_isspace(**end)))
	{
		if (ft_strchr("<>|\"'", *(*end + 1)))
			return ;
		else
			(*end)++;
	}
}

void	get_quote(t_token *token, char **begin, char **end)
{
	token->type = T_WORD;
	*end = ft_strchr(*begin + 1, **begin);
	if (!*end)
	{
		printf("인용문이 닫히지 않았습니다!\n");
		// 여기서 입력 계속 받는거 처리
		return ;
	}
	else
		(*end)++;
}

void	get_pipe(t_token *token, char **begin, char **end)
{
	token->type = T_PIPE;
	(*end)++;
}

void	get_redirect_op(t_token *token, char **begin, char **end)
{
	if (**begin == T_IN && *(*begin + 1) == T_IN)
	{
		token->type = T_HEREDOC;
		*end += 2;
	}
	else if (**begin == T_OUT && *(*begin + 1) == T_OUT)
	{
		token->type = T_APPEND;
		*end += 2;
	}
	else if (**begin == T_IN)
	{
		token->type = T_IN;
		(*end)++;
	}
	else if (**begin == T_OUT)
	{
		token->type = T_OUT;
		(*end)++;
	}
}

void	lexical_analysis(t_token *token, char **begin, char **end)
{
	while (ft_isspace(manager.command_line[manager.rc]))
		manager.rc++;
	*begin = &manager.command_line[manager.rc];
	*end = *begin;
	if (**begin == T_DOUBLE_QUOTES || **begin == T_SINGLE_QUOTES)
		get_quote(token, begin, end);
	else if (**begin == T_IN || **begin == T_OUT)
		get_redirect_op(token, begin, end);
	else if (**begin == T_PIPE)
		get_pipe(token, begin, end);
	else
		get_word(token, begin, end);
}

t_token	get_token()
{
	char	*begin;
	char	*end;
	t_token	token;

	token.type = T_NULL;
	token.value = NULL;
	printf("manager.rc: %d\n", manager.rc);
	if (manager.rc >= manager.command_len)
		return (token); // EOF error
	lexical_analysis(&token, &begin, &end);
	token.value = ft_calloc(end - begin + 1, sizeof(char));
	if (!token.value)
		return (token); // malloc error
	if (!ft_strlcpy(token.value, begin, end - begin + 1))
		return (token); // copy error
	manager.rc += end - begin;
	return (token);
}
