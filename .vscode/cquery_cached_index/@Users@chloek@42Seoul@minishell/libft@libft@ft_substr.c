/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 21:35:06 by nkim              #+#    #+#             */
/*   Updated: 2021/09/25 11:30:39 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*res;
	size_t	size;
	size_t	i;

	if (!str)
		return (0);
	size = ft_strlen(str + start);
	if (size > len)
		size = len;
	res = (char *)malloc(sizeof(char) * size + 1);
	if (!res)
		return (0);
	i = 0;
	while (i < len && (start + i) < ft_strlen(str))
	{
		res[i] = str[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
