/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 19:59:06 by nbled             #+#    #+#             */
/*   Updated: 2022/12/03 20:03:49 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_ground_player(t_vars *vars, int x, int y)
{
	if (vars->dir == 'U')
		mlx_put_image_to_window(vars->mlx, vars->win, \
					vars->ground_player_facing_up, (x * 32), (y * 32));
	if (vars->dir == 'L')
		mlx_put_image_to_window(vars->mlx, vars->win, \
					vars->ground_player_facing_left, (x * 32), (y * 32));
	if (vars->dir == 'D')
		mlx_put_image_to_window(vars->mlx, vars->win, \
					vars->ground_player_facing_down, (x * 32), (y * 32));
	if (vars->dir == 'R')
		mlx_put_image_to_window(vars->mlx, vars->win, \
					vars->ground_player_facing_right, (x * 32), (y * 32));
}

void	print_grass_player(t_vars *vars, int x, int y)
{
	if (vars->dir == 'U')
		mlx_put_image_to_window(vars->mlx, vars->win, \
					vars->grass_player_facing_up, (x * 32), (y * 32));
	if (vars->dir == 'L')
		mlx_put_image_to_window(vars->mlx, vars->win, \
					vars->grass_player_facing_left, (x * 32), (y * 32));
	if (vars->dir == 'D')
		mlx_put_image_to_window(vars->mlx, vars->win, \
					vars->grass_player_facing_down, (x * 32), (y * 32));
	if (vars->dir == 'R')
		mlx_put_image_to_window(vars->mlx, vars->win, \
					vars->grass_player_facing_right, (x * 32), (y * 32));
}

void	print_flower_player(t_vars *vars, int x, int y)
{
	if (vars->dir == 'U')
		mlx_put_image_to_window(vars->mlx, vars->win, \
					vars->flower_player_facing_up, (x * 32), (y * 32));
	if (vars->dir == 'L')
		mlx_put_image_to_window(vars->mlx, vars->win, \
					vars->flower_player_facing_left, (x * 32), (y * 32));
	if (vars->dir == 'D')
		mlx_put_image_to_window(vars->mlx, vars->win, \
					vars->flower_player_facing_down, (x * 32), (y * 32));
	if (vars->dir == 'R')
		mlx_put_image_to_window(vars->mlx, vars->win, \
					vars->flower_player_facing_right, (x * 32), (y * 32));
}

void	print_player(t_vars *vars, char **tab, int x, int y)
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
		print_grass_player(vars, x, y);
	else if (i == 1 && (y % 2) == 0)
		print_flower_player(vars, x, y);
	else
		print_ground_player(vars, x, y);
}
