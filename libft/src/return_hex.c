/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 23:14:11 by caalbert          #+#    #+#             */
/*   Updated: 2023/02/02 10:12:54 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	return_hex(unsigned int n, int c)
{
	int	size;

	size = 0;
	if (n >= 16)
	{
		size += return_hex(n / 16, c);
		size += return_hex(n % 16, c);
	}
	if (n < 16)
	{
		if (n < 10)
			size += return_char(n + 48);
		else
		{
			if (c == 1)
				size += return_char(n + 87);
			else
				size += return_char(n + 55);
		}
	}
	return (size);
}
