/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_int_dec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 23:06:25 by caalbert          #+#    #+#             */
/*   Updated: 2023/02/02 10:12:54 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	pointer_to_hexa(int c)
{
	long long	n;
	int			size;

	n = c;
	size = 0;
	if (n < 0)
	{
		size += return_putchar('-');
		n *= -1;
	}
	if (n >= 10)
	{
		size += pointer_to_hexa(n / 10);
		size += pointer_to_hexa(n % 10);
	}
	if (n < 10)
		size += return_char(n + 48);
	return (size);
}
