/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 04:02:20 by nbled             #+#    #+#             */
/*   Updated: 2022/09/09 04:02:22 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_start *start)
{
	size_t	size;

	size = ft_lstsize(start->start_a);
	if (size == 2)
		push_swap_sort_two(start);
	else if (size == 3)
		push_swap_sort_three(start);
	else if (size == 4)
		push_swap_sort_four(start);
	else if (size == 5)
		push_swap_sort_five(start);
	else if (size <= 16)
		push_swap_sort_under_sixteen(start);
	else
		true_push_swap(start);
}
