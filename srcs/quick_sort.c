/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnichola <fnichola@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 16:53:11 by fnichola          #+#    #+#             */
/*   Updated: 2021/12/17 21:34:29 by fnichola         ###   ########.fr       */
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
	}
	push_swap(data);
}
