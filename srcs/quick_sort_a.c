/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnichola <fnichola@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:30:23 by fnichola          #+#    #+#             */
/*   Updated: 2022/02/04 16:46:28 by fnichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	search_ahead_a(
	t_stack_elem *stack_top, t_stack_elem *pivot, int size)
{
	t_stack_elem	*stack_ptr;

	stack_ptr = stack_top;
	while (size--)
	{
		if (stack_ptr->value < pivot->value)
			return (1);
		if (stack_ptr == pivot)
			return (1);
		stack_ptr = stack_ptr->prev;
	}
	return (0);
}

static void	unrotate_a(t_data *data, t_stack_elem *pivot, size_t ra_count)
{
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

void	quick_sort_a(t_data *data)
{
	t_stack_elem	*pivot;
	int				size;
	size_t			ra_count;

	ra_count = 0;
	size = partition_size(data, data->a.top);
	pivot = find_median(data->a.top, size);
	if (!pivot)
		exit_error(data);
	pivot->pivot_marker = 1;
	while (size)
	{
		if (!search_ahead_a(data->a.top, pivot, size))
			break ;
		else if (data->a.top->value < pivot->value)
			do_operation(data, PB);
		else
		{
			do_operation(data, RA);
			ra_count++;
		}
		size--;
	}
	unrotate_a(data, pivot, ra_count);
}
