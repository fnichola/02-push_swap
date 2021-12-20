/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnichola <fnichola@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:21:06 by fnichola          #+#    #+#             */
/*   Updated: 2021/12/17 16:51:23 by fnichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	do_operation(t_data *data, t_operation op_code)
{
	if (op_code == SA)
		ft_stack_swap(&data->a.top);
	else if (op_code == SB)
		ft_stack_swap(&data->b.top);
	else if (op_code == SS)
	{
		ft_stack_swap(&data->a.top);
		ft_stack_swap(&data->b.top);
	}
	else if (op_code == PA)
	{
		if (ft_stack_push(&data->a.top, ft_stack_pop(&data->b.top)))
		{
			data->a.size++;
			data->b.size--;
		}
	}
	else if (op_code == PB)
	{
		if (ft_stack_push(&data->b.top, ft_stack_pop(&data->a.top)))
		{
			data->a.size--;
			data->b.size++;
		}
	}
	else if (op_code == RA)
		ft_stack_rotate(&data->a.top);
	else if (op_code == RB)
		ft_stack_rotate(&data->b.top);
	else if (op_code == RR)
	{
		ft_stack_rotate(&data->a.top);
		ft_stack_rotate(&data->b.top);
	}
	else if (op_code == RRA)
		ft_stack_rrotate(&data->a.top);
	else if (op_code == RRB)
		ft_stack_rrotate(&data->b.top);
	else if (op_code == RRR)
	{
		ft_stack_rrotate(&data->a.top);
		ft_stack_rrotate(&data->b.top);
	}
	data->instruction_count++;
}
