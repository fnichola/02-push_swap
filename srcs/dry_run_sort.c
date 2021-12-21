/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dry_run_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnichola <fnichola@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:20:42 by fnichola          #+#    #+#             */
/*   Updated: 2021/12/21 18:23:29 by fnichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	dry_run_sort(t_stack_elem *start, t_stack_elem *end)
{
	t_stack			stack;
	t_stack_elem	*ptr;

	stack.top = NULL;
	stack.size = 0;
	ptr = start;
	while (ptr && ptr != end)
	{
		ft_stack_push(&stack.top, ft_stack_new_elem(ptr->value));
		ptr = ptr->prev;
	}


}

t_stack_elem	*ft_mid_stack_pop(t_stack **stack, t_stack_elem *popped_element)
{
	if (popped_element == (*stack)->top)
		return (ft_stack_pop(&(*stack)->top));
	if (popped_element->prev)
		popped_element->prev->next = popped_element->next;
	popped_element->next->prev = popped_element->prev;
	popped_element->next = NULL;
	popped_element->prev = NULL;
	return (popped_element);
}

void	ft_stack_push_bottom(t_stack **stack, t_stack_elem *elem)
{
	t_stack_elem	*btm;

	btm = ft_stack_bottom((*stack)->top);
	btm->prev = elem;
	elem->next = btm;
	elem->prev = NULL;
}

void	quick_sort(t_stack **stack, t_stack_elem *start, t_stack_elem *end)
{
	t_stack_elem	*pivot;
	t_stack_elem	*ptr;

	if (start == end)
		return ;
	pivot = (*stack)->top;
	ptr = pivot->prev;
	if (!ptr)
		return ;
	while (ptr)
	{
		if (ptr->value < pivot->value)

	}
	quick_sort(stack,);
	quick_sort(stack,);
}
