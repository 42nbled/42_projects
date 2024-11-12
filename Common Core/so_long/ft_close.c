/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 21:46:50 by nbled             #+#    #+#             */
/*   Updated: 2022/12/04 21:46:52 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_image_ground(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->ground);
	mlx_destroy_image(vars->mlx, vars->ground_player_facing_up);
	mlx_destroy_image(vars->mlx, vars->ground_player_facing_left);
	mlx_destroy_image(vars->mlx, vars->ground_player_facing_down);
	mlx_destroy_image(vars->mlx, vars->ground_player_facing_right);
	mlx_destroy_image(vars->mlx, vars->ground_collectible);
	mlx_destroy_image(vars->mlx, vars->ground_trophee);
}

void	destroy_image_grass(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->grass);
	mlx_destroy_image(vars->mlx, vars->grass_player_facing_up);
	mlx_destroy_image(vars->mlx, vars->grass_player_facing_left);
	mlx_destroy_image(vars->mlx, vars->grass_player_facing_down);
	mlx_destroy_image(vars->mlx, vars->grass_player_facing_right);
	mlx_destroy_image(vars->mlx, vars->grass_collectible);
	mlx_destroy_image(vars->mlx, vars->grass_trophee);
}

void	destroy_image_flower(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->flower);
	mlx_destroy_image(vars->mlx, vars->flower_player_facing_up);
	mlx_destroy_image(vars->mlx, vars->flower_player_facing_left);
	mlx_destroy_image(vars->mlx, vars->flower_player_facing_down);
	mlx_destroy_image(vars->mlx, vars->flower_player_facing_right);
	mlx_destroy_image(vars->mlx, vars->flower_collectible);
	mlx_destroy_image(vars->mlx, vars->flower_trophee);
}

void	free_map(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->map[i])
	{
		free(vars->map[i]);
		i++;
	}
	free(vars->map);
}

int	ft_close(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->three);
	destroy_image_ground(vars);
	destroy_image_grass(vars);
	destroy_image_flower(vars);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free_map(vars);
	free(vars->mlx);
	exit(0);
}
