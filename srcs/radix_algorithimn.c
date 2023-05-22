/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_algorithimn.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 22:07:11 by caalbert          #+#    #+#             */
/*   Updated: 2023/05/17 04:38:25 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_vars_radix	init_vars(t_data *data)
{
	t_vars_radix	vars;

	vars.max_num = data->len - 1;
	vars.bit_count = 0;
	vars.max_bits = 0;
	return (vars);
}

void	sort_radix(t_data *data)
{
	t_vars_radix	vars;

	vars = init_vars(data);
	while ((vars.max_num >> vars.max_bits) != 0)
		vars.max_bits++;
	while (vars.bit_count < vars.max_bits)
	{
		vars.num_count = 0;
		while (vars.num_count < data->len)
		{
			vars.num = data->stack_a->num;
			if (((vars.num >> vars.bit_count) & 1) == 1)
				ra(&(data->stack_a));
			else
				pb(data);
			vars.num_count++;
		}
		vars.bit_count++;
		while (data->stack_b)
			pa(data);
	}
}
