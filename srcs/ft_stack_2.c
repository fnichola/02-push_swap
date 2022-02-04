/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addl_stack_operations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnichola <fnichola@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:21:51 by fnichola          #+#    #+#             */
/*   Updated: 2021/12/14 15:38:45 by fnichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_stack_swap(t_stack_elem **stack_top)
{
	t_stack_elem	*elem1;
	t_stack_elem	*elem2;

	if (!(*stack_top))
		return ;
	if ((*stack_top)->prev)
	{
		elem1 = ft_stack_pop(stack_top);
		elem2 = ft_stack_pop(stack_top);
		ft_stack_push(stack_top, elem1);
		ft_stack_push(stack_top, elem2);
	}
}

void	ft_stack_rotate(t_stack_elem **stack_top)
{
	t_stack_elem	*bottom_elem;
	t_stack_elem	*popped_elem;

	if (!*stack_top)
		return ;
	bottom_elem = ft_stack_bottom(*stack_top);
	popped_elem = ft_stack_pop(stack_top);
	if (popped_elem == bottom_elem)
	{
		ft_stack_push(stack_top, popped_elem);
		return ;
	}
	if (popped_elem && bottom_elem)
	{
		bottom_elem->prev = popped_elem;
		popped_elem->next = bottom_elem;
	}
}

void	ft_stack_rrotate(t_stack_elem **stack_top)
{
	t_stack_elem	*bottom_elem;

	if (!*stack_top)
		return ;
	bottom_elem = ft_stack_bottom(*stack_top);
	if (bottom_elem == *stack_top)
		return ;
	if (bottom_elem && bottom_elem->next)
	{
		bottom_elem->next->prev = NULL;
		bottom_elem->next = NULL;
		ft_stack_push(stack_top, bottom_elem);
	}
}

int	ft_stack_update_size(t_stack *stack)
{
	t_stack_elem	*elem;
	int				size;

	if (!stack)
		return (0);
	elem = stack->top;
	if (!stack->top)
	{
		stack->size = 0;
		return (0);
	}
	size = 1;
	while (elem->prev)
	{
		elem = elem->prev;
		size++;
	}
	stack->size = size;
	return (size);
}
