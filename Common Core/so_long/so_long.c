/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:01:24 by nbled             #+#    #+#             */
/*   Updated: 2022/11/21 18:28:10 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	loop(t_vars *vars)
{
	print_map(vars, vars->map);
	return (0);
}

void	struct_init(t_vars *vars, char **argv)
{
	char	*s;
	int		x;
	int		y;

	s = read_map(argv[1]);
	x = ft_str_len(s, '\n') * 32;
	y = ft_count_words(s, '\n') * 32;
	vars->map = ft_split(s, '\n');
	if (is_valid(vars) == 0)
	{
		free_map(vars);
		free(s);
		exit (0);
	}
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, x, y, "So_long");
	free_map(vars);
	vars->map = ft_split(s, '\n');
	vars->dir = 'D';
	free(s);
	get_end_location(vars);
}

void	so_long(char **argv)
{
	t_vars	vars;

	struct_init(&vars, argv);
	init_img(&vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 17, 0, ft_close, &vars);
	mlx_loop_hook(vars.mlx, loop, &vars);
	mlx_loop(vars.mlx);
	ft_close(&vars);
}

int	is_file_empty(char *argv)
{
	int		fd;
	char	str[1];

	fd = open(argv, O_RDONLY);
	if (!read(fd, str, 1))
	{
		ft_putstr(RED"Error ! Empty file\n"END);
		return (0);
	}
	close(fd);
	return (1);
}

int	main(int argc, char **argv)
{
	int		fd;

	if (argc != 2)
	{
		ft_putstr(RED"Error ! Invalid arguments\n"END);
		return (0);
	}
	if (is_file_empty(argv[1]) == 0)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd > 0)
		so_long(argv);
	else
	{
		ft_putstr(RED"Error ! File not found\n"END);
		return (0);
	}
	return (0);
}
 