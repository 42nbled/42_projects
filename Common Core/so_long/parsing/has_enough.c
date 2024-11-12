/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_enough.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 03:09:24 by nbled             #+#    #+#             */
/*   Updated: 2022/11/29 03:09:26 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_put_error_2(int W, int F)
{
	if (W < 1)
		ft_putstr(RED"Error ! No Wall\n"END);
	if (F < 1)
		ft_putstr(RED"Error ! No empty space\n"END);
	if (W < 1 || F < 1)
		return (0);
	return (1);
}

int	has_enough(char **s, int W, int F)
{
	int	x;
	int	y;

	y = 0;
	while (s[y])
	{
		x = 0;
		while (s[y][x])
		{
			if (s[y][x] == '1')
				W++;
			else if (s[y][x] == '0')
				F++;
			x++;
		}
		y++;
	}
	if (ft_put_error_2(W, F) == 0)
		return (0);
	return (1);
}
