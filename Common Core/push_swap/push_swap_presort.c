/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_presort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 01:06:44 by nbled             #+#    #+#             */
/*   Updated: 2022/09/20 01:06:46 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	second_presort(t_start *start, size_t octile, size_t size)
{
	size_t	index;

	while (start->start_a->next->next != NULL)
	{
		if (start->start_a->index == size - 1 || start->start_a->index == 0)
			rotate("ra", start);
		else
		{
			push("pb", start);
			index = start->start_b->index;
			if (index < octile
				|| (index < octile * 5 && index > octile * 4)
				|| (index < octile * 9 && index > octile * 8)
				|| (index < octile * 13 && index > octile * 12))
				rotate("rb", start);
		}
	}
}

static void	presort_exec(t_start *start, size_t octile, size_t n)
{
	push("pb", start);
	if (start->start_b->index < octile * n)
		rotate("rb", start);
}

static void	presort(t_start *start, size_t octile)
{
	if (start->start_a->index < octile || start->start_a->index > octile * 15)
		rotate("ra", start);
	else if (start->start_a->index < octile * 3
		|| start->start_a->index >= octile * 13)
	{
		push("pb", start);
		if (start->start_b->index < octile * 2
			|| (start->start_b->index < octile * 14
				&& start->start_b->index >= octile * 13))
			rotate("rb", start);
	}
	else if (start->start_a->index < octile * 7
		&& start->start_a->index >= octile * 5)
		presort_exec(start, octile, 6);
	else if (start->start_a->index < octile * 11
		&& start->start_a->index >= octile * 9)
		presort_exec(start, octile, 10);
	else
		rotate("ra", start);
}

size_t	first_presort(t_start *start)
{
	size_t	size;
	size_t	octile;
	size_t	i;

	i = 0;
	size = ft_lstsize(start->start_a);
	octile = size / 16;
	while (i < size)
	{
		presort(start, octile);
		i++;
	}
	second_presort(start, octile, size);
	return (octile);
}
