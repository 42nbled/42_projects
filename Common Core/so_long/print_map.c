/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:53:49 by nbled             #+#    #+#             */
/*   Updated: 2022/11/16 16:53:51 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_ground(t_vars *vars, char **tab, int x, int y)
{
	int	i;

	i = 0;
	if (tab[y + 1][x] == '1')
		i++;
	if (tab[y][x + 1] == '1')
		i++;
	if (tab[y - 1][x] == '1')
		i++;
	if (tab[y][x - 1] == '1')
		i++;
	if (i >= 2)
		mlx_put_image_to_window(vars->mlx, vars->win, \
					vars->grass, (x * 32), (y * 32));
	else if (i == 1 && (y % 2) == 0)
		mlx_put_image_to_window(vars->mlx, vars->win, \
					vars->flower, (x * 32), (y * 32));
	else
		mlx_put_image_to_window(vars->mlx, vars->win, \
					vars->ground, (x * 32), (y * 32));
}

void	print_collectible(t_vars *vars, char **tab, int x, int y)
{
	int	i;

	i = 0;
	if (tab[y + 1][x] == '1')
		i++;
	if (tab[y][x + 1] == '1')
		i++;
	if (tab[y - 1][x] == '1')
		i++;
	if (tab[y][x - 1] == '1')
		i++;
	if (i >= 2)
		mlx_put_image_to_window(vars->mlx, vars->win, \
					vars->grass_collectible, (x * 32), (y * 32));
	else if (i == 1 && (y % 2) == 0)
		mlx_put_image_to_window(vars->mlx, vars->win, \
					vars->flower_collectible, (x * 32), (y * 32));
	else
		mlx_put_image_to_window(vars->mlx, vars->win, \
					vars->ground_collectible, (x * 32), (y * 32));
}

void	print_trophee(t_vars *vars, char **tab, int x, int y)
{
	int	i;

	i = 0;
	if (tab[y + 1][x] == '1')
		i++;
	if (tab[y][x + 1] == '1')
		i++;
	if (tab[y - 1][x] == '1')
		i++;
	if (tab[y][x - 1] == '1')
		i++;
	if (i >= 2)
		mlx_put_image_to_window(vars->mlx, vars->win, \
					vars->grass_trophee, (x * 32), (y * 32));
	else if (i == 1 && (y % 2) == 0)
		mlx_put_image_to_window(vars->mlx, vars->win, \
					vars->flower_trophee, (x * 32), (y * 32));
	else
		mlx_put_image_to_window(vars->mlx, vars->win, \
					vars->ground_trophee, (x * 32), (y * 32));
}

void	print_map(t_vars *vars, char **tab)
{
	int	x;
	int	y;

	y = 0;
	while (tab[y])
	{
		x = 0;
		while (tab[y][x])
		{
			if (tab[y][x] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win,
					vars->three, x * 32, y * 32);
			else if (tab[y][x] == '0')
				print_ground(vars, tab, x, y);
			else if (tab[y][x] == 'C')
				print_collectible(vars, tab, x, y);
			else if (tab[y][x] == 'E')
				print_trophee(vars, tab, x, y);
			else if (tab[y][x] == 'P')
				print_player(vars, tab, x, y);
			x++;
		}
		y++;
	}
}
