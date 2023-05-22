/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 14:07:16 by caalbert          #+#    #+#             */
/*   Updated: 2023/02/02 10:12:54 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static size_t	ft_count_str(char const *s, char c);
static void		ft_table(char const *s, char c, size_t num, char **res);

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	num;

	res = NULL;
	if (!s)
		return (NULL);
	num = ft_count_str(s, c);
	res = (char **)malloc(sizeof(char *) * (num +1));
	if (!res)
		return (NULL);
	ft_table(s, c, num, res);
	return (res);
}

static size_t	ft_count_str(char const *s, char c)
{
	size_t	count;
	char	*tmp;

	tmp = (char *)s;
	count = 0;
	while (*tmp != '\0')
	{
		while (*tmp == c && *tmp != 0)
			++tmp;
		while (*tmp != c && *tmp != 0)
			++tmp;
		if (*(tmp - 1) != c)
			count++;
	}
	return (count);
}

static void	ft_table(char const *s, char c, size_t num, char **res)
{
	size_t	count;
	char	*start_str;
	int		len_word;

	count = 0;
	start_str = (char *)s;
	while (count < num)
	{
		len_word = 0;
		while (*start_str == c && *start_str != 0)
			++start_str;
		while (start_str[len_word] != c && start_str[len_word] != 0)
			len_word++;
		res[count] = ft_substr(start_str, 0, len_word);
		start_str += len_word;
		count++;
	}
	res[count] = 0;
}
