/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnichola <fnichola@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 22:29:14 by fnichola          #+#    #+#             */
/*   Updated: 2022/02/09 15:24:35 by fnichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"

typedef enum e_bool {
	FALSE = 0,
	TRUE = 1
}				t_bool;

typedef struct s_stack_elem {
	int					value;
	int					partition;
	int					pivot_marker;
	struct s_stack_elem	*prev;
	struct s_stack_elem	*next;
}					t_stack_elem;

typedef struct s_stack {
	t_stack_elem	*top;
	int				size;
}				t_stack;

typedef struct s_data {
	t_stack			a;
	t_stack			b;
	t_stack_elem	*sorted;
	size_t			instruction_count;
}				t_data;

typedef enum e_operation {
	SA = 0,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
}				t_operation;

t_stack_elem	*ft_stack_new_elem(int value);
t_stack_elem	*ft_stack_top(t_stack_elem *elem);
t_stack_elem	*ft_stack_bottom(t_stack_elem *elem);
int				ft_stack_push(t_stack_elem **stack_top, t_stack_elem *new_elem);
t_stack_elem	*ft_stack_pop(t_stack_elem **stack_top);
void			ft_stack_swap(t_stack_elem **stack_top);
void			ft_stack_rotate(t_stack_elem **stack_top);
void			ft_stack_rrotate(t_stack_elem **stack_top);
int				ft_stack_update_size(t_stack *stack);
void			do_operation(t_data *data, t_operation op_code);
void			push_swap(t_data *data);
void			quick_sort_a(t_data *data);
void			quick_sort_b(t_data *data);
void			print_stacks(t_data *data);
int				stack_range_size(t_stack_elem *start, t_stack_elem *end);
int				partition_size(t_data *data, t_stack_elem *stack_top);
t_stack_elem	*find_median(t_stack_elem *start, int size);
int				mark_if_sorted_a(t_data *data);
int				partition_size(t_data *data, t_stack_elem *stack_top);
void			do_op_ss(t_data *data);
void			do_op_pa(t_data *data);
void			do_op_pb(t_data *data);
void			do_op_rr(t_data *data);
void			do_op_rrr(t_data *data);
void			exit_error(t_data *data);
long long		ft_atoll(const char *str);
void			smart_rotate_6(t_data *data, t_stack_elem *smallest_elem);
void			free_stacks(t_data *data);

#endif
