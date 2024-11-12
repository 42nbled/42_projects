/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 22:09:18 by nbled             #+#    #+#             */
/*   Updated: 2022/09/05 22:09:20 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_start	*ft_newstruct(void)
{
	t_start	*n;

	n = malloc(sizeof(t_start));
	if (!n)
		return (NULL);
	n->start_a = NULL;
	n->start_b = NULL;
	return (n);
}

static void	*push_swap_free_index(void *start, int *index)
{
	free(index);
	if (start)
		return (start);
	return (NULL);
}

static int	*push_swap_index(int argc, char **argv)
{
	int	*index;
	int	count;
	int	i;
	int	y;

	i = 1;
	index = malloc(sizeof(int) * (argc - 1));
	if (!index)
		return (0);
	while (i < argc)
	{
		y = 1;
		count = 0;
		while (y < argc)
		{
			if (ft_atoi(argv[i]) > ft_atoi(argv[y]))
				count++;
			y++;
		}
		index[i - 1] = count;
		i++;
	}
	return (index);
}

void	*push_swap_parsing(int argc, char **argv)
{
	int		i;
	int		*index;
	void	*start;
	t_pile	*new;
	t_pile	*tmp;

	i = 1;
	tmp = NULL;
	start = NULL;
	index = push_swap_index(argc, argv);
	if (index == 0)
		return (NULL);
	while (i < argc)
	{
		new = ft_lstnew(ft_atoi(argv[i]), index[i - 1]);
		if (!new)
			return (ft_lstclear(start), push_swap_free_index(NULL, index));
		if (i != 1)
			ft_lstadd_back(&tmp, new);
		else
			start = new;
		tmp = new;
		i++;
	}
	return (push_swap_free_index(start, index));
}
