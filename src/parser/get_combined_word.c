/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_combined_word.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:54:25 by nkim              #+#    #+#             */
/*   Updated: 2022/06/30 18:13:22 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
   get_combined_heredoc_word
   combined word for heredoc argv
   - $ not working
*/
char	*get_combined_heredoc_word(void)
{
	char	*combined_word;
	char	*token;
	char	*word;
	char	*tmp;
	char	next;

	next = g_manager.command_line[g_manager.rc];
	token = match(T_WORD);
	if (!token)
		return (NULL);
	combined_word = syntax_heredoc_word(token);
	while (!bs_isspace(next) && fetch_token(GET).type == T_WORD)
	{
		next = g_manager.command_line[g_manager.rc];
		word = syntax_heredoc_word(match(T_WORD));
		tmp = combined_word;
		combined_word = ft_strjoin(combined_word, word);
		free(word);
		free(tmp);
	}
	return (combined_word);
}

/*
   get_combined_word
   combine word until space not found
*/
char	*get_combined_word(void)
{
	char	*combined_word;
	char	*token;
	char	*word;
	char	*tmp;
	char	next;

	next = g_manager.command_line[g_manager.rc];
	token = match(T_WORD);
	if (!token)
		return (NULL);
	combined_word = syntax_word(token);
	while (!bs_isspace(next) && fetch_token(GET).type == T_WORD)
	{
		next = g_manager.command_line[g_manager.rc];
		word = syntax_word(match(T_WORD));
		tmp = combined_word;
		combined_word = ft_strjoin(combined_word, word);
		free(word);
		free(tmp);
	}
	return (combined_word);
}
