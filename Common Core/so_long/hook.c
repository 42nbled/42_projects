/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:38:10 by nbled             #+#    #+#             */
/*   Updated: 2022/11/30 11:38:13 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	coin_count(t_vars *vars)
{
	int	i;
	int	x;
	int	y;

	y = 0;
	i = 0;
	while (vars->map[y])
	{
		x = 0;
		while (vars->map[y][x])
		{
			if (vars->map[y][x] == 'C')
				i++;
			x++;
		}
		y++;
	}
	return (i);
}

void	exit_is_back(t_vars *vars, int x, int y)
{
	if (x == vars->x_end && y == vars->y_end)
		vars->map[y][x] = 'E';
	else
		vars->map[y][x] = '0';
}

void	move_count(void)
{
	static int	mov_count = 0;

	ft_putstr(BLUE);
	ft_putnbr(++mov_count);
	ft_putstr(CYAN" moves\n"END);
}

void	ft_move(t_vars *vars, int updown, int leftright)
{
	int			x;
	int			y;

	y = -1;
	while (vars->map[++y])
	{
		x = -1;
		while (vars->map[y][++x])
		{
			if (vars->map[y][x] == 'P' &&
				vars->map[y + updown][x + leftright] != '1')
			{
				exit_is_back(vars, x, y);
				if (x + leftright == vars->x_end
					&& y + updown == vars->y_end && coin_count(vars) == 0)
					ft_close(vars);
				else
				{
					vars->map[y + updown][x + leftright] = 'P';
					move_count();
				}
				return ;
			}
		}
	}
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 119)
	{
		ft_move(vars, -1, 0);
		vars->dir = 'U';
	}
	else if (keycode == 97)
	{
		ft_move(vars, 0, -1);
		vars->dir = 'L';
	}
	else if (keycode == 115)
	{
		ft_move(vars, 1, 0);
		vars->dir = 'D';
	}
	else if (keycode == 100)
	{	
		ft_move(vars, 0, 1);
		vars->dir = 'R';
	}
	else if (keycode == 65307)
		ft_close(vars);
	return (0);
}
