/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnichola <fnichola@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:26:10 by fnichola          #+#    #+#             */
/*   Updated: 2021/12/07 18:09:03 by fnichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_dlist	*ft_dlstnew(int value)
{
	t_dlist	*new_dlist;

	new_dlist = malloc(sizeof(t_dlist));
	if (!new_dlist)
		return (NULL);
	new_dlist->prev = NULL;
	new_dlist->next = NULL;
	new_dlist->value = value;
	return (new_dlist);
}

t_dlist	*ft_dlstlast(t_dlist *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_dlist	*ft_dlstfirst(t_dlist *lst)
{
	if (!lst)
		return (NULL);
	while (lst->prev)
		lst = lst->prev;
	return (lst);
}

/**
 * Adds the element ’new’ at the end of the list.
*/
void	ft_dlstadd_back(t_dlist **lst, t_dlist *new)
{
	t_dlist	*lst_last;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	lst_last = ft_dlstlast(*lst);
	lst_last->next = new;
	new->prev = lst_last;
}

int	main(int argc, char **argv)
{
	int		i;
	t_dlist	*a;

	a = NULL;
	i = 1;
	while (i < argc)
	{
		ft_dlstadd_back(&a, ft_dlstnew(ft_atoi(argv[i])));
		i++;
	}
	a = ft_dlstfirst(a);
	printf("a:\n");
	while (a)
	{
		printf("%d\n", a->value);
		a = a->next;
	}
	return (0);
}
