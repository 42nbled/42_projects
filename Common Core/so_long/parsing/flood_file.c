/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 03:10:15 by nbled             #+#    #+#             */
/*   Updated: 2022/11/29 03:10:17 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	path_put_error(char **s)
{
	int	x;
	int	y;

	y = 0;
	while (s[y])
	{
		x = 0;
		while (s[y][x])
		{
			if (s[y][x] == 'P' || s[y][x] == 'C' || s[y][x] == 'E')
			{
				ft_putstr(RED"Error ! No path found\n"END);
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

void	flood_file(char **s, int x, int y)
{
	if (s[y][x] == '0' || s[y][x] == 'P' || s[y][x] == 'C' || s[y][x] == 'E')
	{
		s[y][x] = 'F';
		flood_file(s, x + 1, y);
		flood_file(s, x - 1, y);
		flood_file(s, x, y + 1);
		flood_file(s, x, y - 1);
	}
}

int	is_path(char **s)
{
	int	x;
	int	y;

	y = 0;
	while (s[y])
	{
		x = 0;
		while (s[y][x])
		{
			if (s[y][x] == 'P')
				flood_file(s, x, y);
			x++;
		}
		y++;
	}
	if (path_put_error(s) == 0)
		return (0);
	return (1);
}
