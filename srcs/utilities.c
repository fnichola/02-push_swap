/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnichola <fnichola@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 21:03:38 by fnichola          #+#    #+#             */
/*   Updated: 2022/01/26 16:03:42 by fnichola         ###   ########.fr       */
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
