/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_small_numbers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 20:22:46 by caalbert          #+#    #+#             */
/*   Updated: 2023/05/16 20:23:16 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_two(t_data *data)
{
	if (data->stack_a->num > data->stack_a->next->num)
		sa(&(data->stack_a));
}

void	sort_three(t_data *data)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = data->stack_a->num;
	n2 = data->stack_a->next->num;
	n3 = data->stack_a->next->next->num;
	if (n1 > n2 && n1 < n3 && n2 < n3)
		sa(&(data->stack_a));
	if (n1 > n2 && n1 > n3 && n2 < n3)
		ra(&(data->stack_a));
	if (n1 < n2 && n1 > n3 && n2 > n3)
		rra(&(data->stack_a));
	if (n1 > n2 && n1 > n3 && n2 > n3)
	{
		sa(&(data->stack_a));
		rra(&(data->stack_a));
	}
	if (n1 < n2 && n1 < n3 && n2 > n3)
	{
		sa(&(data->stack_a));
		ra(&(data->stack_a));
	}
}

void	sort_five(t_data *data)
{
	int	min;
	int	len;

	len = data->len;
	get_min(data->stack_a, &min);
	push_to_b(data, &min, len);
	if (len == 5)
	{
		len--;
		get_min(data->stack_a, &min);
		push_to_b(data, &min, len);
	}
	sort_three(data);
	pa(data);
	pa(data);
}

void	push_to_b5(t_data *data, int index)
{
	if (index == 0)
		pb(data);
	if (index == 1)
	{
		ra(&(data->stack_a));
		pb(data);
	}
	if (index == 2)
	{
		ra(&(data->stack_a));
		ra(&(data->stack_a));
		pb(data);
	}
	if (index == 3)
	{
		rra(&(data->stack_a));
		rra(&(data->stack_a));
		pb(data);
	}
	if (index == 4)
	{
		rra(&(data->stack_a));
		pb(data);
	}
}

void	push_to_b4(t_data *data, int index)
{
	if (index == 0)
		pb(data);
	if (index == 1)
	{
		ra(&(data->stack_a));
		pb(data);
	}
	if (index == 2)
	{
		ra(&(data->stack_a));
		ra(&(data->stack_a));
		pb(data);
	}
	if (index == 3)
	{
		rra(&(data->stack_a));
		pb(data);
	}
}
