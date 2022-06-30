/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bs_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 18:10:38 by hannkim           #+#    #+#             */
/*   Updated: 2022/06/30 18:23:08 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	*bs_calloc(size_t count, size_t size)
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
