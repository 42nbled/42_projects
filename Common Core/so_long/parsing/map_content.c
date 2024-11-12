/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_content.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 03:09:41 by nbled             #+#    #+#             */
/*   Updated: 2022/11/29 03:09:43 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_put_error(int P, int C, int E)
{
	if (P < 1)
		ft_putstr(RED"Error ! No Player\n"END);
	if (P > 1)
		ft_putstr(RED"Error ! Too many Player\n"END);
	if (E < 1)
		ft_putstr(RED"Error ! No Exit\n"END);
	if (E > 1)
		ft_putstr(RED"Error ! Too many Exit\n"END);
	if (C < 1)
		ft_putstr(RED"Error ! No colletible\n"END);
	if (P != 1 || E != 1 || C < 1)
		return (0);
	return (1);
}

int	map_content(char **s, int P, int C, int E)
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
				P++;
			else if (s[y][x] == 'C')
				C++;
			else if (s[y][x] == 'E')
				E++;
			x++;
		}
		y++;
	}
	if (ft_put_error(P, C, E) == 0)
		return (0);
	return (1);
}
