/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 03:37:14 by nbled             #+#    #+#             */
/*   Updated: 2022/09/06 03:37:16 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_a(t_start *start)
{
	t_pile	*last;

	last = ft_lstlast(start->start_a);
	last->next = start->start_a;
	start->start_a = start->start_a->next;
	last->next->next = NULL;
}

static void	rotate_b(t_start *start)
{
	t_pile	*last;

	last = ft_lstlast(start->start_b);
	last->next = start->start_b;
	start->start_b = start->start_b->next;
	last->next->next = NULL;
}

void	rotate(char *index, t_start *start)
{
	if (ft_strncmp(index, "ra", 2) == 0 && ft_lstsize(start->start_a) > 1)
	{
		rotate_a(start);
		ft_putstr("ra\n");
	}
	if (ft_strncmp(index, "rb", 2) == 0 && ft_lstsize(start->start_b) > 1)
	{
		rotate_b(start);
		ft_putstr("rb\n");
	}
	if (ft_strncmp(index, "rr", 2) == 0)
	{
		if (ft_lstsize(start->start_a) > 1 && ft_lstsize(start->start_b) > 1)
		{
			rotate_a(start);
			rotate_b(start);
			ft_putstr("rr\n");
		}
	}
}
