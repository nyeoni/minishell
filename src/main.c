/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 21:17:33 by nkim              #+#    #+#             */
/*   Updated: 2022/06/01 02:03:15 by hannah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>

int	main (void)
{
	char *prompt;

	while (1)
	{
		prompt = readline("Enter a line : ");
		printf("%s\n", prompt);
	}

	return 0;
}
