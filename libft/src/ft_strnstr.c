/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 21:58:11 by caalbert          #+#    #+#             */
/*   Updated: 2023/02/02 10:12:54 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *str, const char *cursor, size_t len)
{
	size_t	p_len;

	p_len = ft_strlen(cursor);
	if (!p_len)
		return ((char *)str);
	while (*str && p_len <= len--)
	{
		if (ft_strncmp(str, cursor, p_len) == 0)
			return ((char *)str);
		str++;
	}
	return (NULL);
}
