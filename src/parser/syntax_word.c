/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 21:49:33 by nkim              #+#    #+#             */
/*   Updated: 2022/06/28 14:23:32 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
   extract_env_name
   extract env name from token
   - check env name
   - token count
*/
char	*extract_env_name(char *token)
{
	char	*name;
	int		nc;

	nc = 0;
	name = ft_calloc(1, sizeof(char));
	while (ft_isalnum(*token))
	{
		name = ft_realloc(name, nc + 2);
		name[nc] = *token;
		nc++;
		token++;
	}
	name[nc] = '\0';
	return (name);
}

/*
	replace_env_sc
	replace env special character
	- $? : prev program exit_code
*/
char	*replace_env_sc(char *token, char *env_ptr)
{
	char	*sc;
	char	*prev;
	char	*next;
	char	*word;

	if (*(env_ptr + 1) == '?')
		sc = ft_itoa(g_manager.exit_code);
	else
		return (ft_strdup(token));
	prev = ft_substr(token, 0, env_ptr - token);
	env_ptr += ft_strlen(sc);
	word = ft_strjoin(prev, sc);
	free(sc);
	free(prev);
	prev = word;
	next = replace_env(env_ptr + 1);
	word = ft_strjoin(word, next);
	free(prev);
	free(next);
	return (word);
}

/*
	replace_env_name
	replace env_name to env_value
*/
char	*replace_env_name(char *token, char *env_ptr)
{
	char	*name;
	t_env	*env;
	char	*prev;
	char	*next;
	char	*word;

	name = extract_env_name(env_ptr + 1);
	prev = ft_substr(token, 0, env_ptr - token);
	env_ptr += ft_strlen(name);
	env = get_env(name);
	if (env)
	{
		word = ft_strjoin(prev, env->value);
		free(prev);
	}
	else
		word = prev;
	free(name);
	prev = word;
	next = replace_env(env_ptr + 1);
	word = ft_strjoin(word, next);
	free(prev);
	free(next);
	return (word);
}

/*
   replace_env
   replace $env to env variable
   tc: token count
   env_sp: ptr of $ start
*/
char	*replace_env(char *token)
{
	char	*word;
	char	*env_ptr;

	env_ptr = ft_strchr(token, '$');
	while (env_ptr && *(env_ptr + 1) && !(*(env_ptr + 1) == '?'
			|| ft_isalpha(*(env_ptr + 1))))
		env_ptr = ft_strchr(env_ptr + 1, '$');
	if (!env_ptr)
		return (ft_strdup(token));
	if (*(env_ptr + 1) == '?')
		word = replace_env_sc(token, env_ptr);
	else if (ft_isalpha(*(env_ptr + 1)))
		word = replace_env_name(token, env_ptr);
	else
		word = ft_strdup(token);
	return (word);
}

/*
   syntax word
   check syntax of word
   - get rid of quotation
   - replace $word to env
*/
char	*syntax_word(char *token)
{
	char	*word;
	char	*tmp;

	if (*token == U_DOUBLE_QUOTES)
	{
		word = ft_substr(token, 1, ft_strlen(token) - 2);
		tmp = word;
		word = replace_env(word);
		free(tmp);
	}
	else if (*token == U_SINGLE_QUOTES)
		word = ft_substr(token, 1, ft_strlen(token) - 2);
	else
		word = replace_env(token);
	free(token);
	return (word);
}
