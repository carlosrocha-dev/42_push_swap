/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 02:49:17 by caalbert          #+#    #+#             */
/*   Updated: 2023/02/02 10:12:54 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	rec_loop(int nb, int fd)
{
	if (nb >= 10)
	{
		rec_loop(nb / 10, fd);
	}
	ft_putchar_fd((nb % 10) + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	int	int_min;

	int_min = -2147483648;
	if (n == int_min)
	{
		write(fd, "-", 1);
		rec_loop(n / -10, fd);
		write (fd, "8", 1);
	}
	else if (n < 0)
	{
		n *= -1;
		write (fd, "-", 1);
	}
	if (n >= 0)
		rec_loop(n, fd);
}
