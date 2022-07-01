/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_heredoc_word.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:41:19 by nkim              #+#    #+#             */
/*   Updated: 2022/07/01 16:07:40 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
   syntax_heredoc_word
   check syntax of word for heredoc
   - get rid of quotation
   - replace $word to env not working
*/
char	*syntax_heredoc_word(char *token)
{
	char	*word;

	if (*token == U_DOUBLE_QUOTES || *token == U_SINGLE_QUOTES)
		word = ft_substr(token, 1, ft_strlen(token) - 2);
	else
		word = ft_strdup(token);
	free(token);
	return (word);
}
