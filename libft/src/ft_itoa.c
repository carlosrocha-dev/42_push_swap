/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 17:13:38 by caalbert          #+#    #+#             */
/*   Updated: 2023/02/02 10:12:54 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static size_t	size_dig(long int num)
{
	size_t	c;

	c = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		num *= -1;
		c++;
	}
	while (num > 0)
	{
		num = num / 10;
		c++;
	}
	return (c);
}

static char	*dig_allocced(size_t digits)
{
	char	*dest;

	dest = (char *) malloc(sizeof(char) * digits + 1);
	if (!dest)
		return (NULL);
	return (dest);
}

char	*ft_itoa(int n)
{
	char		*dst;
	size_t		digits;
	size_t		i;
	int			temp;
	long int	num;

	num = n;
	digits = size_dig(num);
	dst = dig_allocced(digits);
	i = digits - 1;
	if (num == 0)
		dst[0] = '0';
	if (num < 0)
	{
		dst[0] = '-';
		num *= -1;
	}
	while (num > 0)
	{
		temp = num % 10;
		dst[i--] = temp + '0';
		num = num / 10;
	}
	dst[digits] = '\0';
	return (dst);
}
