/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 04:36:17 by nkim              #+#    #+#             */
/*   Updated: 2022/06/28 20:25:49 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
   get_token
   get token for lexical_analyzer
*/
/*
t_token	get_token(void)
{
	char	*begin;
	char	*end;
	t_token	token;

	token.type = T_NULL;
	token.value = NULL;
	if (g_manager.rc >= ft_strlen(g_manager.command_line))
		return (token); // EOF error
	lexical_analyzer(&token, &begin, &end);
	printf("token_type: %d, token_value: %s\n", token.type, token.value);
	token.value = ft_calloc(end - begin + 1, sizeof(char));
	if (!token.value)
		return (token); // malloc error
	if (!ft_strlcpy(token.value, begin, end - begin + 1))
		return (token); // copy error
	g_manager.rc += end - begin;
	return (token);
	flag : flag is only for quote_error (exception case)
}
*/
t_token	get_token(void)
{
	char	*begin;
	char	*end;
	t_token	token;
	int		flag;

	token.type = T_NULL;
	token.value = NULL;
	flag = lexical_analyzer(&token, &begin, &end);
	if (g_manager.rc >= ft_strlen(g_manager.command_line))
		return (token);
	if (flag == ERROR_FLAG)
		g_manager.exit_code = EXIT_SYNTAXERR;
	token.value = ft_calloc(end - begin + 1, sizeof(char));
	if (!token.value)
		return (token);
	if (!ft_strlcpy(token.value, begin, end - begin + 1))
		return (token);
	g_manager.rc += end - begin;
	return (token);
}

/*
   fetch_token
   fetch token for syntax_analyzer
   GET    -> GET existing token
   UPDATE -> UPDATE token and RETURN existing token
*/
t_token	fetch_token(t_fetch_type type)
{
	static t_token	token;
	t_token			prev_token;

	prev_token = token;
	if (type == GET)
		return (token);
	else if (type == UPDATE)
		token = get_token();
	return (prev_token);
}
