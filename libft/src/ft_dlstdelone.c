/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 05:10:50 by caalbert          #+#    #+#             */
/*   Updated: 2023/05/17 05:10:51 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_dlstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	ft_lstdelone(lst->prev, del);
	ft_lstdelone(lst->next, del);
	del(lst->content);
	free(lst);
}
