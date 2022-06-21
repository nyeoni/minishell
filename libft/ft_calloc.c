/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 20:49:59 by nkim              #+#    #+#             */
/*   Updated: 2022/06/21 11:25:02 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	void	*res;

	res = (void *)malloc(size * count);
	if (!(res))
		exit(EXIT_FAILURE);
	i = 0;
	while (i < size * count)
	{
		*((char *)res + i) = '\0';
		i++;
	}
	return (res);
}
