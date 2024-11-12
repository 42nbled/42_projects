/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_surrounded.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 03:09:04 by nbled             #+#    #+#             */
/*   Updated: 2022/11/29 03:09:06 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	get_y_max(char **s)
{
	int	y_max;

	y_max = 0;
	while (s[y_max])
		y_max++;
	y_max--;
	return (y_max);
}

int	get_x_max(char **s)
{
	int	x_max;

	x_max = 0;
	while (s[0][x_max])
		x_max++;
	x_max--;
	return (x_max);
}

int	is_surrounded(char **s)
{
	int	x;
	int	y;
	int	x_max;
	int	y_max;

	x_max = get_x_max(s);
	y_max = get_y_max(s);
	y = 0;
	while (s[y])
	{
		x = 0;
		while (s[y][x])
		{
			if ((y == 0 || x == 0 || y == y_max || x == x_max)
				&& s[y][x] != '1')
			{
				ft_putstr(RED"Error ! Map is not surrounded\n"END);
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}
