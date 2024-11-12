/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 02:20:24 by nbled             #+#    #+#             */
/*   Updated: 2022/09/04 02:20:32 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sort(int argc, char **argv)
{
	int	i;

	i = 2;
	while (i < argc)
	{
		if (ft_atoi(argv[i]) > ft_atoi(argv[i - 1]))
			i++;
		else
			return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_start	*start;

	if (push_swap_condition(argc, argv) == 0)
	{
		ft_putstr("Error \n");
		return (0);
	}
	if (push_swap_condition(argc, argv) > 0 && is_sort(argc, argv) == 0)
	{
		start = ft_newstruct();
		if (start)
		{
			start->start_a = push_swap_parsing(argc, argv);
			if (start->start_a)
			{
				push_swap(start);
				ft_lstclear(start->start_a);
				ft_lstclear(start->start_b);
			}
			free(start);
		}
	}
	return (0);
}
