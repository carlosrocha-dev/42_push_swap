/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 22:00:53 by caalbert          #+#    #+#             */
/*   Updated: 2023/05/17 03:41:19 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_error(int exit_code)
{
	if (exit_code != 1)
		ft_putstr_fd("Error\n", 2);
	exit(exit_code);
}

int	ft_is_range_int(long num)
{
	return (num >= INT_MIN && num <= INT_MAX);
}

void	ft_exit(t_data *data, int exit_code)
{
	if (data)
	{
		free_stack(&(data->stack_a));
		free_stack(&(data->stack_b));
		free(data);
	}
	if (exit_code)
		exit(exit_code);
}

void	check_if_int(char *argv)
{
	int		i;
	long	num;

	i = 0;
	if (argv[i] == '-')
	{
		if (!argv[++i])
			ft_error(1);
	}
	while (!(argv[i] == '\0'))
	{
		if (!ft_isdigit(argv[i]))
			ft_error(2);
		i++;
	}
	num = ft_atol(argv);
	if (!ft_is_range_int(num))
		ft_error(3);
}

int	check_if_dup(t_dlst *stack_a, int number)
{
	while (stack_a)
	{
		if (number == stack_a->num)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}
