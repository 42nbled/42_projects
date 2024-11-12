/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 08:53:11 by nbled             #+#    #+#             */
/*   Updated: 2022/07/14 02:40:21 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(unsigned int nb, char *base, int j)
{
	if (nb < 16)
	{
		j = ft_putchar(base[nb], j);
	}
	else
	{
		j = ft_puthexa(nb / 16, base, j);
		j = ft_puthexa(nb % 16, base, j);
	}
	return (j);
}
