/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnichola <fnichola@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:26:10 by fnichola          #+#    #+#             */
/*   Updated: 2022/02/04 21:33:04 by fnichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	exit_error(t_data *data)
{
	ft_printf_fd(STDERR_FILENO, "Error\n");
	free_stacks(data);
	exit(EXIT_FAILURE);
}

static int	is_invalid(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '-' && str[i] != '+')
			return (1);
		i++;
	}
	return (0);
}

static int	is_duplicate(int nbr, t_stack_elem *stack_ptr)
{
	while (stack_ptr)
	{
		if (stack_ptr->value == nbr)
			return (1);
		stack_ptr = stack_ptr->prev;
	}
	return (0);
}

static void	init_data(int argc, char **argv, t_data *data)
{
	int				i;
	long long		nbr;
	t_stack_elem	*new_elem;

	data->a.top = NULL;
	data->b.top = NULL;
	data->b.size = 0;
	data->instruction_count = 0;
	i = argc;
	while (--i > 0)
	{
		nbr = ft_atoll(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN || is_invalid(argv[i]) \
		|| is_duplicate(nbr, data->a.top))
			exit_error(data);
		new_elem = ft_stack_new_elem(nbr);
		if (!new_elem)
			exit_error(data);
		ft_stack_push(&data->a.top, new_elem);
	}
	ft_stack_update_size(&data->a);
}

int	main(int argc, char **argv)
{
	t_data	data;

	init_data(argc, argv, &data);
	push_swap(&data);
	free_stacks(&data);
	return (0);
}
