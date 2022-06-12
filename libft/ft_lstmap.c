/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 16:43:00 by nkim              #+#    #+#             */
/*   Updated: 2021/09/25 11:19:38 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*lstclear(t_list **res, void (*del)(void *))
{
	ft_lstclear(res, del);
	return (0);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*tmp;

	if (lst)
	{
		res = (t_list *)malloc(sizeof(t_list));
		if (!(res))
			return (0);
		res->content = (*f)(lst->content);
		tmp = res;
	}
	else
		return (0);
	while (lst)
	{
		tmp->next = (t_list *)malloc(sizeof(t_list));
		if (!tmp)
			return (lstclear(&res, del));
		tmp = tmp->next;
		tmp->content = (*f)(lst->content);
		lst = lst->next;
	}
	tmp->next = NULL;
	return (res);
}
