/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnichola <fnichola@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:13:43 by fnichola          #+#    #+#             */
/*   Updated: 2021/12/08 23:06:11 by fnichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*ft_stack_new_elem(int value)
{
	t_stack	*new_elem;

	new_elem = malloc(sizeof(t_stack));
	if (!new_elem)
		return (NULL);
	new_elem->prev = NULL;
	new_elem->next = NULL;
	new_elem->value = value;
	return (new_elem);
}

t_stack	*ft_stack_top(t_stack *elem)
{
	if (!elem)
		return (NULL);
	while (elem->next)
		elem = elem->next;
	return (elem);
}

t_stack	*ft_stack_bottom(t_stack *elem)
{
	if (!elem)
		return (NULL);
	while (elem->prev)
		elem = elem->prev;
	return (elem);
}


void	ft_stack_push(t_stack **stack_top, t_stack *new_elem)
{
	if (*stack_top == NULL)
	{
		*stack_top = new_elem;
		return ;
	}
	(*stack_top)->next = new_elem;
	new_elem->prev = *stack_top;
	*stack_top = new_elem;
}

t_stack	*ft_stack_pop(t_stack **stack_top)
{
	t_stack	*popped_elem;

	popped_elem = *stack_top;
	*stack_top = (*stack_top)->prev;
	if (*stack_top)
		(*stack_top)->next = NULL;
	popped_elem->prev = NULL;
	return (popped_elem);
}
