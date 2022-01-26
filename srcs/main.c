/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnichola <fnichola@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:26:10 by fnichola          #+#    #+#             */
/*   Updated: 2022/01/26 16:18:26 by fnichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	exit_error(void)
{
	ft_printf_fd(STDERR_FILENO, "Error!\n");
	exit(EXIT_FAILURE);
}

static void	init_data(int argc, char **argv, t_data *data)
{
	int		i;

	data->a.top = NULL;
	data->b.top = NULL;
	data->b.size = 0;
	data->instruction_count = 0;
	i = argc;
	while (--i > 0)
		ft_stack_push(&data->a.top, ft_stack_new_elem(ft_atoi(argv[i])));
	ft_stack_update_size(&data->a);
}

int	main(int argc, char **argv)
{
	t_data	data;

	init_data(argc, argv, &data);
	push_swap(&data);
	return (0);
}
