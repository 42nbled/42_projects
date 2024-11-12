/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 03:39:27 by nbled             #+#    #+#             */
/*   Updated: 2022/12/05 03:39:30 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_end_location(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (vars->map[y])
	{
		x = 0;
		while (vars->map[y][x])
		{
			if (vars->map[y][x] == 'E')
			{
				vars->x_end = x;
				vars->y_end = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

char	*read_map(char *path)
{
	char	*line;
	char	*s;
	int		fd;

	s = NULL;
	line = "NULL";
	fd = open(path, O_RDONLY);
	while (line != NULL)
	{
		line = get_next_line(fd);
		s = ft_strjoin(s, line);
		free(line);
	}
	return (s);
}
