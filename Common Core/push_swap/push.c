/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 03:33:16 by nbled             #+#    #+#             */
/*   Updated: 2022/09/06 03:33:18 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_b(t_start *start)
{
	t_pile	*tmp;

	tmp = start->start_a->next;
	start->start_a->next = start->start_b;
	start->start_b = start->start_a;
	start->start_a = tmp;
}

static void	push_a(t_start *start)
{
	t_pile	*tmp;

	tmp = start->start_b->next;
	start->start_b->next = start->start_a;
	start->start_a = start->start_b;
	start->start_b = tmp;
}

void	push(char *index, t_start *start)
{
	if (ft_strncmp(index, "pb", 2) == 0 && ft_lstsize(start->start_a) > 0)
	{
		push_b(start);
		ft_putstr("pb\n");
	}
	if (ft_strncmp(index, "pa", 2) == 0 && ft_lstsize(start->start_b) > 0)
	{
		push_a(start);
		ft_putstr("pa\n");
	}
}
