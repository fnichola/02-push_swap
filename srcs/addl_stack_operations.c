/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addl_stack_operations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnichola <fnichola@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:21:51 by fnichola          #+#    #+#             */
/*   Updated: 2021/12/13 18:50:08 by fnichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_stack_swap(t_stack **stack_top)
{
	t_stack	*elem1;
	t_stack	*elem2;

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

void	ft_stack_rotate(t_stack **stack_top)
{
	t_stack	*bottom_elem;
	t_stack	*popped_elem;

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

void	ft_stack_rrotate(t_stack **stack_top)
{
	t_stack	*bottom_elem;

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
