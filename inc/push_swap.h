/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:11:30 by caalbert          #+#    #+#             */
/*   Updated: 2023/05/17 03:40:03 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

# define LEN_INT 10

typedef struct s_dlst
{
	int				num;
	struct s_dlst	*next;
	struct s_dlst	*prev;
}				t_dlst;

typedef struct s_data
{
	t_dlst	*stack_a;
	t_dlst	*stack_b;
	int		len;
}				t_data;

typedef struct s_vars_radix
{
	int		max_num;
	int		max_bits;
	int		bit_count;
	int		num_count;
	int		num;
	t_dlst	*stack_head;
}				t_vars_radix;

// error_manage.c
int		ft_error(int exit_code);
void	ft_exit(t_data *data, int exit_code);
void	check_if_int(char *argv);
int		check_if_dup(t_dlst *stack_a, int number);

// ft_dlists.c
t_dlst	*ft_dlstnew(int num);
void	ft_dlstadd_front(t_dlst **lst, int num);
t_dlst	*ft_dlstlast(t_dlst *lst);
void	ft_dlstadd_back(t_dlst **lst, int num);
size_t	ft_dlst_len(t_dlst *lst);

// ops_push.c
void	push(t_dlst **stack_0, t_dlst **stack_1);
void	pa(t_data	*data);
void	pb(t_data	*data);

// ops_rotate_reverse.c
void	rotate_reverse(t_dlst **stack);
void	rra(t_dlst **stack_a);
void	rrb(t_dlst **stack_b);
void	rrr(t_data *data);

// ops_rotate.c
void	rotate(t_dlst **stack);
void	ra(t_dlst **stack_a);
void	rb(t_dlst **stack_b);
void	rr(t_data *data);

// ops_swap.c
void	swap(t_dlst **stack);
void	sa(t_dlst **stack_a);
void	sb(t_dlst **stack_b);
void	ss(t_data *data);

// sort_big.c
void	sort_big(t_data *data);

// sort_radix.c
void	sort_radix(t_data *data);

// sort_small_utils.c
int		is_sorted(t_dlst *stack);
void	get_min(t_dlst *stack, int *min);
void	push_to_b(t_data *data, int *min, int len);
void	check_no_args(int argc);

// sort_small.c
void	sort_two(t_data *data);
void	sort_three(t_data *data);
void	sort_five(t_data *data);
void	push_to_b5(t_data *data, int index);
void	push_to_b4(t_data *data, int index);

void	ft_dlstdelone(t_dlst *lst, void (*del)(void *));
void	free_stack(t_dlst **stack);

#endif