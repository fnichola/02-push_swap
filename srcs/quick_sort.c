/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnichola <fnichola@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 16:53:11 by fnichola          #+#    #+#             */
/*   Updated: 2021/12/20 23:25:30 by fnichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * @brief Return element before partition or bottom element,
 * whichever comes first.
 * 
 * @param stack_top 
 * @return t_stack_elem* 
 */
static t_stack_elem	*select_pivot(t_stack_elem *stack_top)
{
	t_stack_elem	*ptr;

	ptr = stack_top;
	while (ptr)
	{
		if (!ptr->prev || ptr->prev->partition)
			break ;
		else
			ptr = ptr->prev;
	}
	return (ptr);
}

void	quick_sort_a(t_data *data)
{
	t_stack_elem	*pivot;
	size_t			ra_count;

	ra_count = 0;
	pivot = select_pivot(data->a.top);
	while (data->a.top != pivot)
	{
		if (data->a.top->value < pivot->value)
			do_operation(data, PB);
		else
		{
			do_operation(data, RA);
			ra_count++;
		}
	}
	pivot->partition = 1;
	do_operation(data, PB);
	while (ra_count > 0)
	{
		do_operation(data, RRA);
		ra_count--;
	}
}

void	quick_sort_b(t_data *data)
{
	t_stack_elem	*pivot;

	pivot = ft_stack_bottom(data->a.top);
	while (data->a.top != pivot)
	{
		if (data->a.top->value < pivot->value)
			do_operation(data, PB);
		else
			do_operation(data, RA);
		print_stacks(data);
	}
}
