/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnichola <fnichola@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:43:52 by fnichola          #+#    #+#             */
/*   Updated: 2022/01/26 15:56:36 by fnichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	do_op_ss(t_data *data)
{
	ft_stack_swap(&data->a.top);
	ft_stack_swap(&data->b.top);
}

void	do_op_pa(t_data *data)
{
	if (ft_stack_push(&data->a.top, ft_stack_pop(&data->b.top)))
	{
		data->a.size++;
		data->b.size--;
	}
}

void	do_op_pb(t_data *data)
{
	if (ft_stack_push(&data->b.top, ft_stack_pop(&data->a.top)))
	{
		data->a.size--;
		data->b.size++;
	}
}

void	do_op_rr(t_data *data)
{
	ft_stack_rotate(&data->a.top);
	ft_stack_rotate(&data->b.top);
}

void	do_op_rrr(t_data *data)
{
	ft_stack_rrotate(&data->a.top);
	ft_stack_rrotate(&data->b.top);
}
