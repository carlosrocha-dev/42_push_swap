/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operating_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 22:07:02 by caalbert          #+#    #+#             */
/*   Updated: 2023/05/17 03:41:43 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	push(t_dlst **stack_0, t_dlst **stack_1)
{
	int		num;
	t_dlst	*old_first;

	num = (*stack_0)->num;
	old_first = (*stack_0);
	(*stack_0) = (*stack_0)->next;
	if (*stack_0)
		(*stack_0)->prev = NULL;
	free(old_first);
	ft_dlstadd_front(stack_1, num);
}

void	pa(t_data	*data)
{
	if (!(data->stack_b))
		return ;
	push(&(data->stack_b), &(data->stack_a));
	write(1, "pa\n", 3);
}

void	pb(t_data	*data)
{
	if (!(data->stack_a))
		return ;
	push(&(data->stack_a), &(data->stack_b));
	write(1, "pb\n", 3);
}
