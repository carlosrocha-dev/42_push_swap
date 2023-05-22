/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 04:39:39 by caalbert          #+#    #+#             */
/*   Updated: 2023/05/17 05:10:31 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

# define HEX_LOWER "0123456789abcdef"
# define BUFFER_SIZE 1024
# define MAX_FD 256
# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_abs(int x);
int		ft_atoi(const char *nptr);
long	ft_atol(const char *nptr);
void	ft_bzero(void *s, size_t n);
void	ft_dlstclear(t_list **list);
int		ft_isdigit(int c);
int		ft_isalpha(int c);
int		ft_isalnum(int c);
int		ft_isspace(int c);
int		ft_is_int_limit(long value);
size_t	ft_strlen(const char *s);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strnstr(const char *str, const char *little, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strcpy(char *dest, const char *src);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
int		min(int a, int b);
int		ft_toupper(int c);
int		ft_tolower(int c);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_itoa(int n);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
int		ft_printf(const char *str, ...);
int		parser_args(char str, va_list *buffer);
int		return_char(char c);
int		return_str(char *str);
int		return_putchar(char c);
int		pointer_to_hexa(int c);
// size_t	ft_strlen(const char *s);
int		return_int_dec(unsigned int c);
int		return_unsigned(unsigned int c);
int		return_hex(unsigned int n, int c);
int		return_pointer(unsigned long int n);
char	*get_next_line(int fd);

#endif
