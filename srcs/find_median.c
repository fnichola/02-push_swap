/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnichola <fnichola@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:20:42 by fnichola          #+#    #+#             */
/*   Updated: 2022/02/04 16:46:52 by fnichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

void	quick_sort(int **array, size_t start, size_t end);

static int	*init_array(t_stack_elem *start, int size)
{
	t_stack_elem	*ptr;
	int				*array;
	int				i;

	array = malloc(sizeof(int) * size);
	if (!array)
		return (NULL);
	i = 0;
	ptr = start;
	while (i < size)
	{
		array[i] = ptr->value;
		ptr = ptr->prev;
		i++;
	}
	return (array);
}

t_stack_elem	*find_median(t_stack_elem *start, int size)
{
	t_stack_elem	*ptr;
	int				*array;
	int				median_value;
	int				i;

	if (size == 0)
		return (NULL);
	array = init_array(start, size);
	if (!array)
		return (NULL);
	quick_sort(&array, 0, size - 1);
	median_value = array[size / 2];
	free(array);
	ptr = start;
	i = 0;
	while (i < size)
	{
		if (ptr->value == median_value)
			break ;
		ptr = ptr->prev;
		i++;
	}
	return (ptr);
}

static void	array_swap(int **array, size_t a, size_t b)
{
	int	temp;

	temp = (*array)[a];
	(*array)[a] = (*array)[b];
	(*array)[b] = temp;
}

static void	quick_sort_loop(size_t start, int **array, int pivot, size_t end)
{
	size_t	i;
	size_t	p;

	p = start;
	i = start + 1;
	while (i <= end)
	{
		if ((*array)[i] < pivot)
		{
			if (i == p + 1)
				array_swap(array, i, p);
			else
			{
				array_swap(array, p, p + 1);
				array_swap(array, i, p);
			}
			p++;
		}
		i++;
	}
	if (p > start)
		quick_sort(array, start, p - 1);
	if (p < end)
		quick_sort(array, p + 1, end);
}

void	quick_sort(int **array, size_t start, size_t end)
{
	int		pivot;

	if (start == end)
		return ;
	if (start + 1 == end && (*array)[start] < (*array)[end])
		return ;
	pivot = (*array)[start];
	quick_sort_loop(start, array, pivot, end);
}
