/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_under_sixteen.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 01:47:32 by nbled             #+#    #+#             */
/*   Updated: 2022/09/16 01:47:35 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	start_is_sort(t_start *start)
{
	unsigned int	previous;
	t_pile			*ptr;

	ptr = start->start_b;
	previous = ptr->index;
	ptr = ptr->next;
	while (ptr)
	{
		if (ptr->index > previous)
			return (0);
		previous = ptr->index;
		ptr = ptr->next;
	}
	return (1);
}

static int	end_is_sort(t_start *start)
{
	unsigned int	previous;
	t_pile			*ptr;

	ptr = start->start_a;
	previous = ptr->index;
	ptr = ptr->next;
	while (ptr)
	{
		if (ptr->index < previous)
			return (0);
		previous = ptr->index;
		ptr = ptr->next;
	}
	return (1);
}

static void	sort_to_b(t_start *start)
{
	while (start->start_a != NULL && end_is_sort(start) == 0)
	{
		if (start->start_b != NULL )
			if (start->start_a->next != NULL && start->start_b->next != NULL)
				if (start->start_b->index < start->start_b->next->index
					&& start->start_a->index > start->start_a->next->index)
					swap("ss", start);
		if (start->start_a->next != NULL)
			if (start->start_a->index > start->start_a->next->index)
				swap("sa", start);
		if (start->start_b != NULL )
			if (start->start_b->next != NULL)
				if (start->start_b->index < start->start_b->next->index)
					swap("sb", start);
		push("pb", start);
	}
}

static void	sort_to_a(t_start *start)
{
	while (start->start_b != NULL && start_is_sort(start) == 0)
	{
		if (start->start_a != NULL )
			if (start->start_a->next != NULL && start->start_b->next != NULL)
				if (start->start_b->index < start->start_b->next->index
					&& start->start_a->index > start->start_a->next->index)
					swap("ss", start);
		if (start->start_b->next != NULL)
			if (start->start_b->index < start->start_b->next->index)
				swap("sb", start);
		if (start->start_a != NULL )
			if (start->start_a->next != NULL)
				if (start->start_a->index > start->start_a->next->index)
					swap("sa", start);
		push("pa", start);
	}
}

void	push_swap_sort_under_sixteen(t_start *start)
{
	while (!(end_is_sort(start) == 1 && start->start_b == NULL))
	{
		sort_to_b(start);
		sort_to_a(start);
		if (end_is_sort(start) == 1 && start_is_sort(start) == 1)
			while (start->start_b)
				push("pa", start);
	}
}
