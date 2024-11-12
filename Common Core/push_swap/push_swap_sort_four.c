/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_four.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 01:47:11 by nbled             #+#    #+#             */
/*   Updated: 2022/09/16 01:47:13 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_sort_four(t_start *s)
{
	while (ft_lstsize(s->start_a) != 2)
	{
		if (s->start_a->index < 2)
			push("pb", s);
		else
			rotate("ra", s);
	}
	if (s->start_b->index < s->start_b->next->index && s->start_a->index == 3)
		swap("ss", s);
	else if (s->start_b->index < s->start_b->next->index)
		swap("sb", s);
	else if (s->start_a->index == 3)
		swap("sa", s);
	push("pa", s);
	push("pa", s);
}
