/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical_analyzer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 14:11:59 by nkim              #+#    #+#             */
/*   Updated: 2022/06/30 18:40:00 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	get_word(t_token *token, char **end)
{
	token->type = T_WORD;
	while (**end && (!bs_isspace(**end)) && !ft_strchr("<>|\"'", **end))
		(*end)++;
}

static void	get_quote(t_token *token, char **end)
{
	token->type = T_WORD;
	*end = ft_strchr(*end + 1, **end);
	if (!*end)
	{
		throw_error("syntax error", NULL, "unexpected end of file");
		*end = g_manager.command_line + ft_strlen(g_manager.command_line);
		g_manager.quote_error = 1;
	}
	else
		(*end)++;
}

static void	get_pipe(t_token *token, char **end)
{
	token->type = T_PIPE;
	(*end)++;
}

static void	get_redirect_op(t_token *token, char **end)
{
	token->type = T_REDIRECT;
	if (**end == U_IN && *(*end + 1) == U_IN)
		*end += 2;
	else if (**end == U_OUT && *(*end + 1) == U_OUT)
		*end += 2;
	else if (**end == U_IN)
		(*end)++;
	else if (**end == U_OUT)
		(*end)++;
}

int	lexical_analyzer(t_token *token, char **begin, char **end)
{
	while (bs_isspace(g_manager.command_line[g_manager.rc]))
		g_manager.rc++;
	*begin = &g_manager.command_line[g_manager.rc];
	*end = *begin;
	if (g_manager.rc >= (int)ft_strlen(g_manager.command_line))
		return (ERROR_FLAG);
	if ((**begin == U_DOUBLE_QUOTES || **begin == U_SINGLE_QUOTES))
		get_quote(token, end);
	else if (**begin == U_IN || **begin == U_OUT)
		get_redirect_op(token, end);
	else if (**begin == U_PIPE)
		get_pipe(token, end);
	else
		get_word(token, end);
	if (g_manager.quote_error)
		return (ERROR_FLAG);
	else
		return (SUCCESS_FLAG);
}
