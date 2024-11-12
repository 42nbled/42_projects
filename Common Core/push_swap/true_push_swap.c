/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   true_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 14:27:11 by nbled             #+#    #+#             */
/*   Updated: 2022/09/11 14:27:14 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	final_sort(t_start *start, size_t base)
{
	size_t	size;
	size_t	i;

	i = 0;
	size = ft_lstsize(start->start_b);
	while (i < size)
	{
		if (start->start_b->index > base)
		{
			while (start->start_b->index > start->start_a->index)
				rotate("ra", start);
			while (start->start_b->index < ft_lstlast(start->start_a)->index)
				reverse_rotate("rra", start);
			push("pa", start);
		}
		else
			rotate("rb", start);
		i++;
	}
}

void	true_push_swap(t_start *start)
{
	size_t	octile;

	octile = first_presort(start);
	final_sort(start, octile * 12);
	final_sort(start, octile * 8);
	final_sort(start, octile * 4);
	while (start->start_b != NULL)
	{
		while (start->start_b->index > start->start_a->index)
			rotate("ra", start);
		while (start->start_b->index < ft_lstlast(start->start_a)->index)
			reverse_rotate("rra", start);
		push("pa", start);
	}
	while (start->start_a->index != 0)
		reverse_rotate("rra", start);
}
