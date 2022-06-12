/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 14:11:59 by nkim              #+#    #+#             */
/*   Updated: 2022/06/12 15:25:23 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		get_word(char **begin, char **end)
{
	while (**end && (!ft_isspace(**end) || ft_strchr("<>|", **end)))
		(*end)++;
	return (SUCCESS_FLAG);
}

int		get_quote(char **begin, char **end)
{
	*end = ft_strchr(*begin + 1, **begin);
	if (!*end)
	{
		printf("인용문이 닫히지 않았습니다!\n");
		return (ERROR_FLAG);
	}
	else
	{
		(*end)++;
		return (SUCCESS_FLAG);
	}
}

int lexical_analysis(char **begin, char **end)
{
	int flag;

	flag = SUCCESS_FLAG;
	*begin = &manager.command_line[manager.rc];
	while (ft_isspace(manager.command_line[manager.rc]))
		manager.rc++;

	*end = *begin;
	if (**begin == T_DOUBLE_QUOTES || **begin == T_SINGLE_QUOTES)
		flag = get_quote(begin, end);
	else if (((**begin == T_IN && *(*begin + 1) == T_IN)
			|| (**begin == T_OUT && *(*begin + 1) == T_OUT)))
		*end += 2;
	else if (**begin == T_IN || **begin == T_OUT)
		(*end)++;
	else if (**begin == T_PIPE)
		(*end)++;
	else
		flag = get_word(begin, end);
	if (flag == SUCCESS_FLAG)
		return (SUCCESS_FLAG);
	else
		return (ERROR_FLAG);
}


char	*get_token()
{
	char	*begin;
	char	*end;
	char	*token;

	if (manager.rc >= manager.command_len)
		return (0);
	// 이 케이스는 인용문이 안닫혔을 경우 밖에 없음
	if (lexical_analysis(&begin, &end))
		return (0);
	token = ft_calloc(end - begin + 1, sizeof(char));
	if (!token)
		return (0);
	if (!ft_strlcpy(token, begin, end - begin + 1))
		return (0);
	manager.rc += end - begin + 1;

	return (token);
}
