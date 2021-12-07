/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnichola <fnichola@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 22:29:14 by fnichola          #+#    #+#             */
/*   Updated: 2021/12/07 16:59:35 by fnichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

typedef struct	s_dlist {
	struct s_dlist	*prev;
	int			value;
	struct s_dlist	*next;
}				t_dlist;
