/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_five.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 01:47:18 by nbled             #+#    #+#             */
/*   Updated: 2022/09/16 01:47:23 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_sort_five(t_start *s)
{
	while (ft_lstsize(s->start_a) != 3)
	{
		if (s->start_a->index < 2)
			push("pb", s);
		else
			rotate("ra", s);
	}
	if (s->start_a->index == 4)
		rotate("ra", s);
	if (s->start_a->next->index == 4)
		reverse_rotate("rra", s);
	if (s->start_b->index < s->start_b->next->index && s->start_a->index == 3)
		swap("ss", s);
	else if (s->start_b->index < s->start_b->next->index)
		swap("sb", s);
	else if (s->start_a->index == 3)
		swap("sa", s);
	push("pa", s);
	push("pa", s);
}
