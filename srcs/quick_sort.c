/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnichola <fnichola@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 16:53:11 by fnichola          #+#    #+#             */
/*   Updated: 2022/01/04 19:42:06 by fnichola         ###   ########.fr       */
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
// static t_stack_elem	*select_pivot(t_stack_elem *stack_top)
// {
// 	t_stack_elem	*ptr;

// 	ptr = stack_top;
// 	while (ptr)
// 	{
// 		if (!ptr->prev || ptr->prev->partition)
// 			break ;
// 		else
// 			ptr = ptr->prev;
// 	}
// 	return (ptr);
// }

void	quick_sort_a(t_data *data)
{
	t_stack_elem	*pivot;
	int				size;
	size_t			ra_count;

	ra_count = 0;
	size = partition_size(data, data->a.top);
	// ft_printf("size = %d\n", size);
	pivot = find_median(data->a.top, size);
	// ft_printf("pivot = %d\n", pivot->value);
	pivot->pivot_marker = 1;
	// print_stacks(data);
	while (size--)
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
	pivot->pivot_marker = 0;
	if (data->a.top == pivot && ra_count == 0)
		do_operation(data, PB);
	while (ra_count > 0)
	{
		do_operation(data, RRA);
		if (data->a.top == pivot)
			do_operation(data, PB);
		ra_count--;
	}
}

void	quick_sort_b(t_data *data)
{
	t_stack_elem	*pivot;
	size_t			rb_count;
	int				size;

	rb_count = 0;
	size = partition_size(data, data->b.top);
	// ft_printf("size = %d\n", size);
	if (data->b.top->partition)
	{
		data->b.top->partition = 0;
		do_operation(data, PA);
		return ;
	}
	else if (size <= 2)
	{
		while (data->b.top && !data->b.top->partition)
			do_operation(data, PA);
		return ;
	}
	pivot = find_median(data->b.top, size);
	// ft_printf("pivot = %d\n", pivot->value);
	pivot->pivot_marker = 1;
	// print_stacks(data);
	while (size--)
	{
		if (data->b.top->value > pivot->value)
			do_operation(data, PA);
		else
		{
			do_operation(data, RB);
			rb_count++;
		}
	}
	while (rb_count > 0)
	{
		if (data->b.top == pivot)
			do_operation(data, PA);
		else
		{
			do_operation(data, RRB);
			rb_count--;
		}
	}
	if (data->a.top == pivot)
		do_operation(data, PB);
	pivot->pivot_marker = 0;
	pivot->partition = 1;
}
