/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnichola <fnichola@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:21:06 by fnichola          #+#    #+#             */
/*   Updated: 2022/01/04 19:45:58 by fnichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	*op_code_to_str(t_operation op_code)
{
	if (op_code == SA)
		return "sa";
	else if (op_code == SB)
		return "sb";
	else if (op_code == SS)
		return "ss";
	else if (op_code == PA)
		return "pa";
	else if (op_code == PB)
		return "pb";
	else if (op_code == RA)
		return "ra";
	else if (op_code == RB)
		return "rb";
	else if (op_code == RR)
		return "rr";
	else if (op_code == RRA)
		return "rra";
	else if (op_code == RRB)
		return "rrb";
	else if (op_code == RRR)
		return "rrr";
	else
		return "";
}

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
	ft_printf("%s\n", op_code_to_str(op_code));
	// print_stacks(data);
}
