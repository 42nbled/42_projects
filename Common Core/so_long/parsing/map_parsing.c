/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 20:09:38 by nbled             #+#    #+#             */
/*   Updated: 2022/11/19 20:09:40 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	is_valid(t_vars *vars)
{
	int	i;

	i = 0;
	if (is_rectangular(vars->map) == 0)
		i++;
	if (is_surrounded(vars->map) == 0)
		i++;
	if (has_enough(vars->map, 0, 0) == 0)
		i++;
	if (map_content(vars->map, 0, 0, 0) == 0)
		i++;
	if (map_composition(vars->map, 0, 0) == 0)
		i++;
	if (i == 0)
		if (is_path(vars->map) == 0)
			i++;
	if (i != 0)
		return (0);
	return (1);
}
