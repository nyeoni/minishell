/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 21:49:33 by nkim              #+#    #+#             */
/*   Updated: 2022/06/23 17:08:01 by nkim             ###   ########.fr       */
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
   replace_env
   replace $env to env variable
   tc: token count
   env_sp: ptr of $ start
*/
char	*replace_env(char *token)
{
	char	*name;
	char	*word;
	char	*env_ptr;
	char	*prev;
	char	*next;

	env_ptr = ft_strchr(token, '$');
	while (env_ptr && *(env_ptr + 1) && !ft_isalpha(*(env_ptr + 1)))
		env_ptr = ft_strchr(env_ptr + 1, '$');
	if (env_ptr && *(env_ptr + 1) && ft_isalpha(*(env_ptr + 1)))
	{
		name = extract_env_name(env_ptr + 1);
		prev = ft_substr(token, 0, env_ptr - token);
		word = ft_strjoin(prev, get_env(name)->value);
		free(name);
		free(prev);
		prev = word;
		next = replace_env(env_ptr + 1);
		word = ft_strjoin(word, next);
		free(prev);
		free(next);
	}
	else
		word = ft_strdup(token);
	return (word);
}

/*
   syntax_heredoc_word
   check syntax of word for heredoc
   - get rid of quotation
   - replace $word to env not working
*/
char	*syntax_heredoc_word(char *token)
{
	char	*word;
	char	*tmp;

	if (*token == U_DOUBLE_QUOTES || *token == U_SINGLE_QUOTES)
		word = ft_substr(token, 1, ft_strlen(token) - 2);
	else
		word = ft_strdup(token);
	free(token);
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
