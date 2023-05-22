/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operating_reverse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 22:01:03 by caalbert          #+#    #+#             */
/*   Updated: 2023/03/04 22:01:04 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rotate_reverse(t_dlst **stack)
{
	t_dlst	*last;

	if (!(*stack))
		return ;
	last = ft_dlstlast(*stack);
	last->prev->next = NULL;
	(*stack)->prev = last;
	last->prev = NULL;
	last->next = (*stack);
	(*stack) = last;
}

void	rra(t_dlst **stack_a)
{
	rotate_reverse(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_dlst **stack_b)
{
	rotate_reverse(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_data *data)
{
	rotate_reverse(&(data->stack_a));
	rotate_reverse(&(data->stack_b));
	write(1, "rrr\n", 4);
}
