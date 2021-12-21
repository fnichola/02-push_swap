/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnichola <fnichola@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:43:43 by fnichola          #+#    #+#             */
/*   Updated: 2021/12/21 14:47:36 by fnichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_stack_elem *stack_top)
{
	t_stack_elem	*ptr;

	if (!stack_top)
		return (1);
	if (stack_top->prev)
	{
		ptr = stack_top->prev;
		while (ptr && !ptr->partition)
		{
			if (ptr->value < ptr->next->value)
				return (0);
			ptr = ptr->prev;
		}
		if (ptr)
			ptr->partition = 0;
	}
	stack_top->partition = 1;
	return (1);
}

static void	sort_2(t_data *data)
{
	if (data->a.top->value > data->a.top->prev->value)
		do_operation(data, SA);
}

static void	sort_3(t_data *data)
{
	int	top;
	int	mid;
	int	btm;

	top = data->a.top->value;
	mid = data->a.top->prev->value;
	btm = data->a.top->prev->prev->value;
	if (top > mid && mid < btm && btm > top)
		do_operation(data, SA);
	else if (top > mid && mid > btm && btm < top)
	{
		do_operation(data, SA);
		do_operation(data, RRA);
	}
	else if (top > mid && mid < btm && btm < top)
		do_operation(data, RA);
	else if (top < mid && mid > btm && btm > top)
	{
		do_operation(data, SA);
		do_operation(data, RA);
	}
	else if (top < mid && mid > btm && btm < top)
		do_operation(data, RRA);
}

static void	sort_6(t_data *data)
{
	t_stack_elem	*ptr;
	t_stack_elem	*smallest_elem;

	while (data->a.size > 3)
	{
		ptr = data->a.top;
		smallest_elem = data->a.top;
		while (ptr)
		{
			if (ptr->value < smallest_elem->value)
				smallest_elem = ptr;
			ptr = ptr->prev;
		}
		while (data->a.top != smallest_elem)
			do_operation(data, RRA);
		do_operation(data, PB);
	}
	sort_3(data);
	while (data->b.size > 0)
		do_operation(data, PA);
}

int	partition_size(t_stack_elem *stack_top)
{
	t_stack_elem	*ptr;
	int				size;

	ptr = stack_top;
	size = 0;
	while (ptr && !ptr->partition)
	{
		ptr = ptr->prev;
		size++;
	}
	return (size);
}

void	push_swap(t_data *data)
{
	int	part_size;

	// ft_printf("push_swap!\n");
	part_size = partition_size(data->a.top);
	// ft_printf("part_size = %d\n", part_size);
	// print_stacks(data);
	if (part_size <= 1 && data->b.size == 0)
		return ;
	else if (is_sorted(data->a.top) && data->b.size == 0)
		return ;
	else if (part_size == 2)
		sort_2(data);
	else if (data->a.size == 3 && data->b.size == 0)
		sort_3(data);
	else if (data->a.size <= 6 && data->b.size == 0)
		sort_6(data);
	else if (part_size > 2)
		quick_sort_a(data);
	else
		quick_sort_b(data);
	push_swap(data);
}
