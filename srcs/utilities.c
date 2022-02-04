/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnichola <fnichola@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 21:03:38 by fnichola          #+#    #+#             */
/*   Updated: 2022/02/04 16:55:03 by fnichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	mark_if_sorted_a(t_data *data)
{
	t_stack_elem	*ptr;

	if (data->a.top && data->a.top->prev)
	{
		ptr = data->a.top->prev;
		while (ptr)
		{
			if (ptr->value < ptr->next->value)
				return (0);
			ptr = ptr->prev;
		}
	}
	data->sorted = data->a.top;
	return (1);
}

/**
 *  Count elements up to, but not including, 
 *  "sorted" or "partition" marker in provided stack.
 */
int	partition_size(t_data *data, t_stack_elem *stack_top)
{
	t_stack_elem	*ptr;
	int				size;

	ptr = stack_top;
	size = 0;
	while (ptr)
	{
		if (ptr->partition || ptr == data->sorted)
			break ;
		size++;
		ptr = ptr->prev;
	}
	return (size);
}

void	smart_rotate_6(t_data *data, t_stack_elem *smallest_elem)
{
	int				i;
	t_stack_elem	*ptr;

	i = 0;
	ptr = data->a.top;
	while (ptr != smallest_elem)
	{
		i++;
		ptr = ptr->prev;
	}
	if (i > data->a.size / 2)
		while (data->a.top != smallest_elem)
			do_operation(data, RRA);
	else
		while (data->a.top != smallest_elem)
			do_operation(data, RA);
}

void	free_stacks(t_data *data)
{
	while (data->a.top)
		free(ft_stack_pop(&data->a.top));
	while (data->b.top)
		free(ft_stack_pop(&data->b.top));
}
