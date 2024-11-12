/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 20:17:43 by nbled             #+#    #+#             */
/*   Updated: 2022/07/11 20:36:09 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int nb, int j)
{
	if (nb < 10)
		j = ft_putchar(nb + 48, j);
	else
	{
		j = ft_putunsigned(nb / 10, j);
		j = ft_putunsigned(nb % 10, j);
	}
	return (j);
}
