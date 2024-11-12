/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:23:11 by nbled             #+#    #+#             */
/*   Updated: 2022/12/03 17:23:12 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_ground(t_vars *vars, int img_width, int img_height)
{
	vars->ground = mlx_xpm_file_to_image
		(vars->mlx, "images/ground.xpm",
			&img_width, &img_height);
	vars->ground_player_facing_up = mlx_xpm_file_to_image
		(vars->mlx, "images/ground_player_facing_up.xpm",
			&img_width, &img_height);
	vars->ground_player_facing_left = mlx_xpm_file_to_image
		(vars->mlx, "images/ground_player_facing_left.xpm",
			&img_width, &img_height);
	vars->ground_player_facing_down = mlx_xpm_file_to_image
		(vars->mlx, "images/ground_player_facing_down.xpm",
			&img_width, &img_height);
	vars->ground_player_facing_right = mlx_xpm_file_to_image
		(vars->mlx, "images/ground_player_facing_right.xpm",
			&img_width, &img_height);
	vars->ground_collectible = mlx_xpm_file_to_image
		(vars->mlx, "images/ground_collectible.xpm",
			&img_width, &img_height);
	vars->ground_trophee = mlx_xpm_file_to_image
		(vars->mlx, "images/ground_trophee.xpm",
			&img_width, &img_height);
}

void	init_grass(t_vars *vars, int img_width, int img_height)
{
	vars->grass = mlx_xpm_file_to_image
		(vars->mlx, "images/grass.xpm",
			&img_width, &img_height);
	vars->grass_player_facing_up = mlx_xpm_file_to_image
		(vars->mlx, "images/grass_player_facing_up.xpm",
			&img_width, &img_height);
	vars->grass_player_facing_left = mlx_xpm_file_to_image
		(vars->mlx, "images/grass_player_facing_left.xpm",
			&img_width, &img_height);
	vars->grass_player_facing_down = mlx_xpm_file_to_image
		(vars->mlx, "images/grass_player_facing_down.xpm",
			&img_width, &img_height);
	vars->grass_player_facing_right = mlx_xpm_file_to_image
		(vars->mlx, "images/grass_player_facing_right.xpm",
			&img_width, &img_height);
	vars->grass_collectible = mlx_xpm_file_to_image
		(vars->mlx, "images/grass_collectible.xpm",
			&img_width, &img_height);
	vars->grass_trophee = mlx_xpm_file_to_image
		(vars->mlx, "images/grass_trophee.xpm",
			&img_width, &img_height);
}

void	init_flower(t_vars *vars, int img_width, int img_height)
{
	vars->flower = mlx_xpm_file_to_image
		(vars->mlx, "images/flower.xpm",
			&img_width, &img_height);
	vars->flower_player_facing_up = mlx_xpm_file_to_image
		(vars->mlx, "images/flower_player_facing_up.xpm",
			&img_width, &img_height);
	vars->flower_player_facing_left = mlx_xpm_file_to_image
		(vars->mlx, "images/flower_player_facing_left.xpm",
			&img_width, &img_height);
	vars->flower_player_facing_down = mlx_xpm_file_to_image
		(vars->mlx, "images/flower_player_facing_down.xpm",
			&img_width, &img_height);
	vars->flower_player_facing_right = mlx_xpm_file_to_image
		(vars->mlx, "images/flower_player_facing_right.xpm",
			&img_width, &img_height);
	vars->flower_collectible = mlx_xpm_file_to_image
		(vars->mlx, "images/flower_collectible.xpm",
			&img_width, &img_height);
	vars->flower_trophee = mlx_xpm_file_to_image
		(vars->mlx, "images/flower_trophee.xpm",
			&img_width, &img_height);
}

void	init_img(t_vars *vars)
{
	int	img_width;
	int	img_height;

	vars->three = mlx_xpm_file_to_image
		(vars->mlx, "images/three.xpm",
			&img_width, &img_height);
	init_ground(vars, img_width, img_height);
	init_grass(vars, img_width, img_height);
	init_flower(vars, img_width, img_height);
}
