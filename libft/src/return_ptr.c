/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 23:12:53 by caalbert          #+#    #+#             */
/*   Updated: 2023/02/02 10:12:54 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*hexa_to_string(unsigned long int n, char *base);
static int	lenght_hex(unsigned long int n);

int	return_pointer(unsigned long int n)
{
	int		size;
	char	*str;

	size = 0;
	if (!n)
	{
		size += write (1, "(nil)", 5);
		return (size);
	}
	else
	{
		size += write(1, "0x", 2);
		str = hexa_to_string(n, HEX_LOWER);
	}
	size += write(1, str, ft_strlen(str));
	free(str);
	return (size);
}

static char	*hexa_to_string(unsigned long int n, char *base)
{
	char	*hex;
	int		size;

	size = lenght_hex(n);
	hex = (char *)malloc(size + 1);
	if (!hex)
		return (NULL);
	hex[size--] = '\0';
	while (n > 0)
	{
		hex[size--] = base[n % 16];
		n /= 16;
	}
	if (size == 0 && hex[1] == '\0')
		hex[0] = 48;
	return (hex);
}

static int	lenght_hex(unsigned long int n)
{
	unsigned long int	size;

	size = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 16;
		size++;
	}
	return (size);
}
