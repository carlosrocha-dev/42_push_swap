/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_lists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 22:00:59 by caalbert          #+#    #+#             */
/*   Updated: 2023/03/04 22:01:00 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_dlst	*ft_dlstnew(int num)
{
	t_dlst	*lnew;

	lnew = (t_dlst *) malloc(sizeof(t_dlst));
	if (!lnew)
		return (0);
	lnew->num = num;
	lnew->next = NULL;
	lnew->prev = NULL;
	return (lnew);
}

void	ft_dlstadd_front(t_dlst **lst, int num)
{
	t_dlst	*new;
	t_dlst	*old_first;

	new = ft_dlstnew(num);
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	old_first = (*lst);
	old_first->prev = new;
	*lst = new;
	new->prev = NULL;
	new->next = old_first;
}

t_dlst	*ft_dlstlast(t_dlst *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_dlstadd_back(t_dlst **lst, int num)
{
	t_dlst	*new;
	t_dlst	*tmp;

	new = ft_dlstnew(num);
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = ft_dlstlast(*lst);
	tmp->next = new;
	new->prev = tmp;
	new->next = NULL;
}

size_t	ft_dlst_len(t_dlst *lst)
{
	size_t	len;

	len = 0;
	while (lst)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}
