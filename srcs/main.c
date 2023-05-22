/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 18:44:14 by caalbert          #+#    #+#             */
/*   Updated: 2023/05/17 03:43:06 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	print_error_and_exit(t_data *data)
{
	write(2, "Error\n", 6);
	if (data)
	{
		if (data->stack_a)
			ft_dlstdelone(data->stack_a, free);
		free(data);
	}
	exit(1);
}

void	free_stack(t_dlst **stack)
{
	t_dlst	*tmp;

	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
}

t_data	*init_data(char **argv)
{
	t_data	*data;
	int		i;
	int		number;

	data = (t_data *) malloc(sizeof(t_data));
	if (!data)
		ft_exit(data, 4);
	data->stack_b = NULL;
	i = 1;
	number = (int) ft_atoi(argv[i++]);
	data->stack_a = ft_dlstnew(number);
	while (argv[i])
	{
		number = (int) ft_atoi(argv[i++]);
		if (check_if_dup(data->stack_a, number))
			print_error_and_exit(data);
		ft_dlstadd_back(&data->stack_a, number);
	}
	data->len = ft_dlst_len(data->stack_a);
	return (data);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	int		i;

	i = 1;
	if (argc <= 1)
		return (0);
	while (i < argc)
	{
		check_if_int(argv[i]);
		i++;
	}
	data = init_data(argv);
	if (is_sorted(data->stack_a))
		return (0);
	else if (argc == 3)
		sort_two(data);
	else if (argc == 4)
		sort_three(data);
	else if (argc > 4 && argc < 7)
		sort_five(data);
	else
		sort_big(data);
	ft_exit(data, 0);
	return (0);
}
