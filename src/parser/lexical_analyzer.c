/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical_analyzer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 14:11:59 by nkim              #+#    #+#             */
/*   Updated: 2022/06/20 17:31:09 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_word(t_token *token, char **begin, char **end)
{
	token->type = T_WORD;
	while (**end && (!ft_isspace(**end)) && !ft_strchr("<>|\"'", **end))
		(*end)++;
}

// TODO: 인용문이 닫히지 않았을 때 처리하기
void	get_quote(t_token *token, char **begin, char **end)
{
	token->type = T_WORD;
	*end = ft_strchr(*begin + 1, **begin);
	if (!*end)
	{
		printf("인용문이 닫히지 않았습니다!\n");
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
	token->type = T_REDIRECT;
	if (**begin == U_IN && *(*begin + 1) == U_IN)
		*end += 2;
	else if (**begin == U_OUT && *(*begin + 1) == U_OUT)
		*end += 2;
	else if (**begin == U_IN)
		(*end)++;
	else if (**begin == U_OUT)
		(*end)++;
}

void	lexical_analyzer(t_token *token, char **begin, char **end)
{
	while (ft_isspace(g_manager.command_line[g_manager.rc]))
		g_manager.rc++;
	*begin = &g_manager.command_line[g_manager.rc];
	*end = *begin;
	if (**begin == U_DOUBLE_QUOTES || **begin == U_SINGLE_QUOTES)
		get_quote(token, begin, end);
	else if (**begin == U_IN || **begin == U_OUT)
		get_redirect_op(token, begin, end);
	else if (**begin == U_PIPE)
		get_pipe(token, begin, end);
	else
		get_word(token, begin, end);
}
