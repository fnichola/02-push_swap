/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnichola <fnichola@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 22:29:14 by fnichola          #+#    #+#             */
/*   Updated: 2021/12/14 15:45:01 by fnichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

typedef struct		s_stack_elem {
	int				value;
	struct s_stack_elem	*prev;
	struct s_stack_elem	*next;
}					t_stack_elem;

typedef struct	s_stack {
	t_stack_elem	*top;
	int				size;
}				t_stack;

typedef struct	s_data {
	t_stack		a;
	t_stack		b;
	t_list		*solution;
}				t_data;


t_stack_elem	*ft_stack_new_elem(int value);
t_stack_elem	*ft_stack_top(t_stack_elem *elem);
t_stack_elem	*ft_stack_bottom(t_stack_elem *elem);
void	ft_stack_push(t_stack *stack, t_stack_elem *new_elem);
t_stack_elem	*ft_stack_pop(t_stack_elem **stack_top);
void	ft_stack_swap(t_stack_elem **stack_top);
void	ft_stack_rotate(t_stack_elem **stack_top);
void	ft_stack_rrotate(t_stack_elem **stack_top);
int	ft_stack_update_size(t_stack *stack);
