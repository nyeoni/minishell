/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_io_redirect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 04:59:57 by nkim              #+#    #+#             */
/*   Updated: 2022/06/20 05:00:14 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	syntax_io_redirect(t_io_redirect *io_redirect)
{
	printf("===io_redirect===\n");
	io_redirect = ft_calloc(1, sizeof(t_io_redirect));
	io_redirect->redirect_op = match(T_REDIRECT);
	io_redirect->file_path = match(T_WORD);
	printf("======\n");
}