/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnichola <fnichola@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:26:10 by fnichola          #+#    #+#             */
/*   Updated: 2021/12/21 16:26:05 by fnichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>


static void	init_data(int argc, char **argv, t_data *data)
{
	int		i;

	data->a.top = NULL;
	data->b.top = NULL;
	data->b.size = 0;
	data->instruction_count = 0;
	i = argc;
	while (--i > 0)
		ft_stack_push(&data->a.top, ft_stack_new_elem(ft_atoi(argv[i]))); // add malloc error handling!
	ft_stack_update_size(&data->a);
}

void	print_stacks(t_data *data)
{
	t_stack	a;
	t_stack	b;

	a = data->a;
	b = data->b;

	ft_printf("Instructions: %d\n", data->instruction_count);
	while (a.top || b.top)
	{
		if (a.size > b.size)
		{
			ft_printf("%d", a.top->value);
			if (a.top == data->sorted)
				ft_printf("~\n");
			else
				ft_printf("\n");
			a.size--;
			a.top = a.top->prev;
		}
		else if (b.size > a.size)
		{
			ft_printf(" \t%d", b.top->value);
			if (b.top->partition)
				ft_printf("*\n");
			else
				ft_printf("\n");
			b.size--;
			b.top = b.top->prev;
		}
		else
		{
			ft_printf("%d", a.top->value);
			if (a.top == data->sorted)
				ft_printf("~\t");
			else
				ft_printf("\t");
			ft_printf("%d", b.top->value);
			if (b.top->partition)
				ft_printf("*\n");
			else
				ft_printf("\n");
			a.size--;
			b.size--;
			a.top = a.top->prev;
			b.top = b.top->prev;
		}
	}
	ft_printf("_\t_\na\tb\n\n");
	getchar();
}

int	main(int argc, char **argv)
{
	t_data	data;

	init_data(argc, argv, &data);
	print_stacks(&data);
	push_swap(&data);
	print_stacks(&data);
	return (0);
}
