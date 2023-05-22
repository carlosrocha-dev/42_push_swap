/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 22:08:22 by caalbert          #+#    #+#             */
/*   Updated: 2023/05/17 03:21:43 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	check_no_args(int argc)
{
	if (argc <= 1)
		;
}

int	is_sorted(t_dlst *stack)
{
	while (stack->next)
	{
		if (stack->num < stack->next->num)
			stack = stack->next;
		else
			break ;
	}
	if (!(stack->next))
		return (1);
	return (0);
}

void	get_min(t_dlst *stack, int *min)
{
	*min = stack->num;
	while (stack->next)
	{
		if (*min > stack->next->num)
			*min = stack->next->num;
		stack = stack->next;
	}
}

void	push_to_b(t_data *data, int *min, int len)
{
	int		index;
	t_dlst	*lst;

	index = 0;
	lst = data->stack_a;
	while (lst->next)
	{
		if (lst->num == *min)
			break ;
		index++;
		lst = lst->next;
	}
	if (len == 5)
		push_to_b5(data, index);
	if (len == 4)
		push_to_b4(data, index);
}

void	ft_dlstdelone(t_dlst *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	if (lst->prev)
		lst->prev->next = lst->next;
	if (lst->next)
		lst->next->prev = lst->prev;
	del(lst);
}
