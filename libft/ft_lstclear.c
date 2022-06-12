/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 03:24:27 by nkim              #+#    #+#             */
/*   Updated: 2021/06/19 19:05:18 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	while ((*lst)->next)
	{
		tmp = *lst;
		*lst = tmp->next;
		(*del)(tmp->content);
		free(tmp);
		tmp = 0;
	}
	(*del)((*lst)->content);
	free(*lst);
	*lst = 0;
}
