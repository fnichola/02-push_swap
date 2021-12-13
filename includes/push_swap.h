/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnichola <fnichola@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 22:29:14 by fnichola          #+#    #+#             */
/*   Updated: 2021/12/13 18:51:39 by fnichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

typedef struct		s_stack {
	struct s_stack	*prev;
	int				value;
	struct s_stack	*next;
}					t_stack;

t_stack	*ft_stack_new_elem(int value);
t_stack	*ft_stack_top(t_stack *elem);
t_stack	*ft_stack_bottom(t_stack *elem);
void	ft_stack_push(t_stack **stack_top, t_stack *new_elem);
t_stack	*ft_stack_pop(t_stack **stack_top);
void	ft_stack_swap(t_stack **stack_top);
void	ft_stack_rotate(t_stack **stack_top);
void	ft_stack_rrotate(t_stack **stack_top);
