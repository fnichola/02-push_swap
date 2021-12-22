/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dry_run_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnichola <fnichola@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:20:42 by fnichola          #+#    #+#             */
/*   Updated: 2021/12/22 17:59:52 by fnichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

void	quick_sort(int **array, size_t start, size_t end);
int		g_size;

void	print_array(int **array)
{
	for (int i = 0; i < g_size; i++)
	{
		printf("%d ", (*array)[i]);
	}
	printf("\n");
	getchar();
}

void	dry_run_sort(t_stack_elem *start, t_stack_elem *end)
{
	t_stack_elem	*ptr;
	size_t			size;
	int				*array;

	size = 0;
	ptr = start;
	while (ptr && ptr != end)
	{
		size++;
		ptr = ptr->prev;
	}
	// if size == 0?
	array = malloc(sizeof(int)*size);
	// if (!array)
		// exit(); // do something better?
	quick_sort(&array, 0, size - 1);
}

static void		array_swap(int **array, size_t a, size_t b)
{
	int	temp;

	temp = (*array)[a];
	(*array)[a] = (*array)[b];
	(*array)[b] = temp;
}

void	quick_sort(int **array, size_t start, size_t end)
{
	int		pivot;
	size_t	i;
	size_t	p;

	if (start == end)
		return ;
	if (start + 1 == end && (*array)[start] < (*array)[end])
		return ;
	pivot = (*array)[start];
	p = start;
	i = start + 1;
	while (i <= end)
	{
		if ((*array)[i] < pivot)
		{
			if (i == p + 1)
			{
				array_swap(array, i, p);
				p++;
			}
			else
			{
				array_swap(array, p, p + 1);
				array_swap(array, i, p);
				p++;
			}
		}
		i++;
	}
	print_array(array);
	if (p > start)
		quick_sort(array, start, p - 1);
	if (p < end)
		quick_sort(array, p + 1, end);
}

int	main(int argc, char **argv)
{
	int	*array;

	if (argc < 2)
		return (0);
	g_size = argc - 1;
	array = malloc(sizeof(int) * (argc - 1));
	for (int i = 0; i < (argc - 1); i++)
	{
		array[i] = atoi(argv[i + 1]);
	}
	print_array(&array);
	quick_sort(&array, 0, argc - 2);
	free(array);
	return (0);
}
