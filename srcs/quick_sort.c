/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnichola <fnichola@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 16:53:11 by fnichola          #+#    #+#             */
/*   Updated: 2021/12/20 15:27:34 by fnichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	quick_sort(t_data *data)
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
	do_operation(data, PB);
	ft_lstadd_front(&data->b_partitions, ft_lstnew(data->b.top));
	print_stacks(data);
	push_swap(data);
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
	push_swap(data);
}
