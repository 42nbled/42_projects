/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 20:29:53 by nbled             #+#    #+#             */
/*   Updated: 2022/07/14 02:42:44 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printptr(unsigned long long nb, char *base, int j)
{
	if (nb < 16)
	{
		j = ft_putchar(base[nb], j);
	}
	else
	{
		j = ft_printptr(nb / 16, base, j);
		j = ft_printptr(nb % 16, base, j);
	}
	return (j);
}

int	ft_putptr(unsigned long long nb, char *base, int j)
{
	if (nb == 0)
		j = ft_putstr ("(nil)", j);
	else
	{
		j = ft_putstr("0x", j);
		j = ft_printptr(nb, base, j);
	}
	return (j);
}
