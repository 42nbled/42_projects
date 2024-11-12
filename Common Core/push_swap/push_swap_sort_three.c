/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_three.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 01:47:01 by nbled             #+#    #+#             */
/*   Updated: 2022/09/16 01:47:03 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_sort_three(t_start *start)
{
	if (start->start_a->index == 2)
		rotate("ra", start);
	if (start->start_a->next->index == 2)
		reverse_rotate("rra", start);
	if (start->start_a->index == 1)
		swap("sa", start);
}
