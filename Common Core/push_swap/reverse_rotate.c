/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 04:35:50 by nbled             #+#    #+#             */
/*   Updated: 2022/09/08 04:36:05 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate_a(t_start *start)
{
	t_pile	*last;
	size_t	size;

	last = ft_lstlast(start->start_a);
	size = ft_lstsize(start->start_a);
	last->next = start->start_a;
	start->start_a = last;
	while (size-- > 1)
		last = last->next;
	last->next = NULL;
}

static void	reverse_rotate_b(t_start *start)
{
	t_pile	*last;
	size_t	size;

	last = ft_lstlast(start->start_b);
	size = ft_lstsize(start->start_b);
	last->next = start->start_b;
	start->start_b = last;
	while (size-- > 1)
		last = last->next;
	last->next = NULL;
}

void	reverse_rotate(char *index, t_start *start)
{
	if (ft_strncmp(index, "rra", 3) == 0 && ft_lstsize(start->start_a) > 1)
	{
		reverse_rotate_a(start);
		ft_putstr("rra\n");
	}
	if (ft_strncmp(index, "rrb", 3) == 0 && ft_lstsize(start->start_b) > 1)
	{
		reverse_rotate_b(start);
		ft_putstr("rrb\n");
	}
	if (ft_strncmp(index, "rrr", 3) == 0)
	{
		if (ft_lstsize(start->start_a) > 1 && ft_lstsize(start->start_b) > 1)
		{
			reverse_rotate_a(start);
			reverse_rotate_b(start);
			ft_putstr("rrr\n");
		}
	}
}
