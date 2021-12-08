/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnichola <fnichola@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:26:10 by fnichola          #+#    #+#             */
/*   Updated: 2021/12/08 23:09:51 by fnichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>


static void	init_stack_a(int argc, char **argv, t_stack **a_top)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		ft_stack_push(a_top, ft_stack_new_elem(ft_atoi(argv[i])));
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a_top;

	a_top = NULL;
	init_stack_a(argc, argv, &a_top);
	//ft_stack_swap(&a_top);
	ft_stack_rotate(&a_top);
	while (a_top)
	{
		ft_printf("%d\n", a_top->value);
		free(ft_stack_pop(&a_top));
	}
	ft_printf("---\n a \n");
	return (0);
}
