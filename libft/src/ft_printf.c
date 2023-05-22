/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 18:57:41 by caalbert          #+#    #+#             */
/*   Updated: 2022/08/22 03:04:17 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	parser_args(char input, va_list *buffer);

int	ft_printf(const char *fmt, ...)
{
	va_list	buffer;
	int		size;
	int		i;

	size = 0;
	i = 0;
	va_start(buffer, fmt);
	while (fmt[i] != '\0')
	{
		if (fmt[i] != '%')
			size += write (1, &fmt[i], 1);
		if (fmt[i] == '%')
		{
			size += parser_args(fmt[i + 1], &buffer);
			i++;
		}
		i++;
	}
	va_end(buffer);
	return (size);
}

int	parser_args(char input, va_list *buffer)
{
	int	size;

	size = 0;
	if (input == '\0')
		return (0);
	else if (input == 'c')
		size += return_char(va_arg(*buffer, int));
	else if (input == 's')
		size += return_str(va_arg(*buffer, char *));
	else if (input == 'p')
		size += return_pointer(va_arg(*buffer, unsigned long int));
	else if (input == 'd' || input == 'i')
		size += pointer_to_hexa(va_arg(*buffer, int));
	else if (input == 'u')
		size += return_unsigned(va_arg(*buffer, unsigned));
	else if (input == 'x')
		size += return_hex(va_arg(*buffer, unsigned), 1);
	else if (input == 'X')
		size += return_hex(va_arg(*buffer, unsigned), 2);
	else if (input == '%')
		size += return_putchar('%');
	return (size);
}
