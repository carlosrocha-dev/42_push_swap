/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 20:19:59 by caalbert          #+#    #+#             */
/*   Updated: 2023/02/02 10:12:54 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static size_t	ft_strnlen(const char *s, size_t c);

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	srclen;
	size_t	dstlen;

	srclen = ft_strlen(src);
	dstlen = ft_strnlen(dst, size);
	if (dstlen == size)
		return (dstlen + srclen);
	ft_strlcpy(&dst[dstlen], src, size - dstlen);
	return (dstlen + srclen);
}

static size_t	ft_strnlen(const char *s, size_t c)
{
	size_t	i;

	i = 0;
	while (s[i] && i < c)
		i++;
	return (i);
}
