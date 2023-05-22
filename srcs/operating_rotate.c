/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    operating_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 22:01:10 by caalbert          #+#    #+#             */
/*   Updated: 2023/03/04 22:01:11 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rotate(t_dlst **stack)
{
	t_dlst	*last;
	t_dlst	*old_first;

	last = ft_dlstlast((*stack));
	old_first = (*stack);
	(*stack) = (*stack)->next;
	(*stack)->prev = NULL;
	old_first->next = NULL;
	old_first->prev = last;
	last->next = old_first;
}

void	ra(t_dlst **stack_a)
{
	if (!(*stack_a)->next)
		return ;
	rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_dlst **stack_b)
{
	if (!(*stack_b)->next)
		return ;
	rotate(stack_b);
	write(1, "rb\n", 3);
}

void	rr(t_data *data)
{
	rotate(&(data->stack_a));
	rotate(&(data->stack_b));
	write(1, "rr\n", 3);
}
