/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_rectangular.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 03:08:52 by nbled             #+#    #+#             */
/*   Updated: 2022/11/29 03:08:54 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	is_rectangular(char **s)
{
	int	x;
	int	x_max;
	int	y;

	x_max = 0;
	y = 0;
	while (s[y])
	{
		x = 0;
		while (s[y][x])
		{
			x++;
		}
		if (y == 0)
			x_max = x;
		else if (x != x_max)
		{
			ft_putstr(RED"Error ! Map is not rectangular\n"END);
			return (0);
		}
		y++;
	}
	return (1);
}
