/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operating_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 22:01:06 by caalbert          #+#    #+#             */
/*   Updated: 2023/03/04 22:01:07 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	swap(t_dlst **stack)
{
	t_dlst	*second;

	if (!(*stack))
		return ;
	second = (*stack)->next;
	(*stack)->prev = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	if ((*stack)->next)
		(*stack)->next->prev = *(stack);
	second->prev = NULL;
	second->next = (*stack);
	(*stack) = second;
}

void	sa(t_dlst **stack_a)
{
	swap(stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_dlst **stack_b)
{
	swap(stack_b);
	write(1, "sb\n", 3);
}

void	ss(t_data *data)
{
	swap(&(data->stack_a));
	swap(&(data->stack_b));
	write(1, "ss\n", 3);
}
