/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 12:22:44 by nbled             #+#    #+#             */
/*   Updated: 2022/07/10 18:40:18 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size(unsigned int n)
{
	unsigned int	i;
	unsigned int	j;

	i = 1;
	j = 0;
	if (n == 0)
		return (1);
	else if (n > 999999999)
		return (10);
	while (i <= n)
	{
		i *= 10;
		j++;
	}
	return (j);
}

static char	*ft_itoa_cond_one(char *str, unsigned long nbr, int size)
{
	str[size + 1] = '\0';
	while (size >= 0)
	{
		str[size] = ((nbr % 10) + 48);
		nbr /= 10;
		size--;
	}
	str[0] = 45;
	return (str);
}

static char	*ft_itoa_cond_two(char *str, unsigned long nbr, int size)
{
	str[size] = '\0';
	size--;
	while (size >= 0)
	{
		str[size] = ((nbr % 10) + 48);
		nbr /= 10;
		size--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned long	nbr;
	int				size;

	nbr = n;
	if (n < 0)
		nbr *= (-1);
	size = get_size(nbr);
	if (n < 0)
	{
		str = malloc(sizeof(char) * (size + 2));
		if (!str)
			return (NULL);
		return (ft_itoa_cond_one(str, nbr, size));
	}
	str = malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	return (ft_itoa_cond_two(str, nbr, size));
}
