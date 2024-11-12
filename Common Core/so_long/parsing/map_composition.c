/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_composition.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 03:09:52 by nbled             #+#    #+#             */
/*   Updated: 2022/11/29 03:09:53 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	map_composition(char **s, int i, int y)
{
	int	x;

	while (s[y])
	{
		x = 0;
		while (s[y][x])
		{
			if (s[y][x] != '0' && s[y][x] != '1' && s[y][x] != 'C'
			&& s[y][x] != 'E' && s[y][x] != 'P')
			{
				ft_putstr(RED"Error ! "YELLOW);
				ft_putchar(s[y][x]);
				ft_putstr(RED" is not a valid character\n"END);
				i++;
			}
			x++;
		}
		y++;
	}
	if (i != 0)
		return (0);
	return (1);
}
