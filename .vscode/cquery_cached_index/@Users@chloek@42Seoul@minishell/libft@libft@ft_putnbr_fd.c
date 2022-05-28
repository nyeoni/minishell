/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 02:16:20 by nkim              #+#    #+#             */
/*   Updated: 2021/06/22 22:58:22 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char			tmp;
	unsigned int	nbr;

	nbr = n;
	if (n < 0)
	{
		write(fd, "-", 1);
		nbr = n * -1;
	}
	if (nbr < 10)
		tmp = '0' + nbr;
	else
	{
		ft_putnbr_fd(nbr / 10, fd);
		tmp = '0' + (nbr % 10);
	}
	write(fd, &tmp, 1);
}
