/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 03:33:37 by nbled             #+#    #+#             */
/*   Updated: 2022/09/06 03:33:40 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_a(t_start *start)
{
	t_pile	*tmp;

	tmp = start->start_a->next->next;
	start->start_a->next->next = start->start_a;
	start->start_a = start->start_a->next;
	start->start_a->next->next = tmp;
}

static void	swap_b(t_start *start)
{
	t_pile	*tmp;

	tmp = start->start_b->next->next;
	start->start_b->next->next = start->start_b;
	start->start_b = start->start_b->next;
	start->start_b->next->next = tmp;
}

void	swap(char *index, t_start *start)
{
	if (ft_strncmp(index, "sa", 2) == 0 && ft_lstsize(start->start_a) > 1)
	{
		swap_a(start);
		ft_putstr("sa\n");
	}
	if (ft_strncmp(index, "sb", 2) == 0 && ft_lstsize(start->start_b) > 1)
	{
		swap_b(start);
		ft_putstr("sb\n");
	}
	if (ft_strncmp(index, "ss", 2) == 0)
	{
		if (ft_lstsize(start->start_a) > 1 && ft_lstsize(start->start_b) > 1)
		{
			swap_a(start);
			swap_b(start);
			ft_putstr("ss\n");
		}
	}
}
