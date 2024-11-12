/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_condition.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 01:34:19 by nbled             #+#    #+#             */
/*   Updated: 2022/09/06 01:34:22 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_digit(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

static int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
		if (is_digit(str[i++]) == 0)
			return (0);
	return (1);
}

static int	is_integer(char *str, char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if ((str[i] == '-' && ft_strlen(str) == 11) || ft_strlen(str) == 10)
	{
		if (str[i] == '-')
			i++;
		while (j <= 10)
		{
			if (i == 10 && str[i] < '9')
				return (1);
			if (str[i] > base[j])
				return (0);
			if (str[i] < base[j])
				return (1);
			i++;
			j++;
		}
	}
	else if (ft_strlen(str) > 10)
		return (0);
	return (1);
}

static int	is_duplicate(int argc, char **argv)
{
	int	i;
	int	y;

	i = 1;
	while (i < argc)
	{
		y = i + 1;
		while (y < argc)
			if (ft_atoi(argv[i]) == ft_atoi(argv[y++]))
				return (0);
		i++;
	}
	return (1);
}

int	push_swap_condition(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc <= 1)
		return (-1);
	while (i < argc)
	{
		if (is_integer(argv[i], "2147483647") == 0)
			return (0);
		if (is_number(argv[i++]) == 0)
			return (0);
	}
	if (is_duplicate(argc, argv) == 0)
		return (0);
	return (1);
}
