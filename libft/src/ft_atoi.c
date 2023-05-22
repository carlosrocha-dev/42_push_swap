/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 22:23:19 by caalbert          #+#    #+#             */
/*   Updated: 2023/05/17 05:13:50 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_atoi(const char *dest)
{
	int	sign;
	int	num;
	int	a;

	a = 0;
	if (*dest == 0)
		return (0);
	while (dest[a] == ' ' || (dest[a] >= 9 && dest[a] <= 13))
		a++;
	sign = 1;
	if (dest[a] == '+' || dest[a] == '-')
	{
		if (dest[a] == '-')
			sign = -sign;
		a++;
	}
	num = 0;
	while (dest[a] <= '9' && dest[a] >= '0')
	{
		num *= 10;
		num = num + dest[a] - 48;
		a++;
	}
	return (num * sign);
}
