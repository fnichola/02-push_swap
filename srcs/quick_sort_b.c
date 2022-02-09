/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnichola <fnichola@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:30:27 by fnichola          #+#    #+#             */
/*   Updated: 2022/02/09 15:23:17 by fnichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_bool	search_ahead_b(
	t_stack_elem *stack_top, t_stack_elem *pivot, int size)
{
	t_stack_elem	*stack_ptr;

	stack_ptr = stack_top;
	while (size--)
	{
		if (stack_ptr->value > pivot->value)
			return (TRUE);
		if (stack_ptr == pivot)
			return (TRUE);
		stack_ptr = stack_ptr->prev;
	}
	return (FALSE);
}

static void	unrotate_b(t_data *data, t_stack_elem *pivot, size_t rb_count)
{
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
}

static void	quick_sort_loop_b(
	t_data *data, t_stack_elem *pivot, size_t *rb_count, int size)
{
	while (size)
	{
		if (!search_ahead_b(data->b.top, pivot, size))
			break ;
		else if (data->b.top->value > pivot->value)
			do_operation(data, PA);
		else
		{
			do_operation(data, RB);
			(*rb_count)++;
		}
		size--;
	}
}

static int	check_stack_top_b(t_data *data, int size)
{
	if (data->b.top->partition)
	{
		data->b.top->partition = 0;
		do_operation(data, PA);
		return (1);
	}
	else if (size <= 2)
	{
		while (data->b.top && !data->b.top->partition)
			do_operation(data, PA);
		return (1);
	}
	else
		return (0);
}

void	quick_sort_b(t_data *data)
{
	t_stack_elem	*pivot;
	size_t			rb_count;
	int				size;

	rb_count = 0;
	size = partition_size(data, data->b.top);
	if (check_stack_top_b(data, size))
		return ;
	pivot = find_median(data->b.top, size);
	if (!pivot)
		exit_error(data);
	pivot->pivot_marker = 1;
	quick_sort_loop_b(data, pivot, &rb_count, size);
	unrotate_b(data, pivot, rb_count);
	if (data->a.top == pivot)
		do_operation(data, PB);
	pivot->pivot_marker = 0;
	pivot->partition = 1;
}
