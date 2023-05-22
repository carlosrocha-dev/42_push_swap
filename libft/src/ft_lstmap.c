/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 22:48:57 by caalbert          #+#    #+#             */
/*   Updated: 2023/02/02 10:12:54 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_dst;
	t_list	*node;

	if (!lst)
		return (NULL);
	lst_dst = NULL;
	while (lst != NULL)
	{
		node = ft_lstnew(f(lst->content));
		if (!node)
		{
			ft_lstclear(&lst_dst, del);
			return (NULL);
		}
		ft_lstadd_back(&lst_dst, node);
		lst = lst->next;
	}
	return (lst_dst);
}
