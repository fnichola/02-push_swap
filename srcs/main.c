/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnichola <fnichola@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:26:10 by fnichola          #+#    #+#             */
/*   Updated: 2021/12/14 15:39:43 by fnichola         ###   ########.fr       */
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
	// data->solution = 
	i = 1;
	while (i < argc)
	{
		ft_stack_push(&data->a.top, ft_stack_new_elem(ft_atoi(argv[i])));
		i++;
	}
	ft_stack_update_size(&data->a);
}

int	main(int argc, char **argv)
{
	t_data	data;

	init_data(argc, argv, &data);
	while (data.a.top)
	{
		ft_printf("%d\n", data.a.top->value);
		free(ft_stack_pop(&data.a.top));
	}
	ft_printf("---\n a \n");
	return (0);
}
