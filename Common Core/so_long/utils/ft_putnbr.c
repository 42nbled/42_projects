/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 20:38:24 by nbled             #+#    #+#             */
/*   Updated: 2022/12/03 20:38:26 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_putnbr2(int nb)
{
	int	tabl[11];
	int	count;
	int	a;

	count = 0;
	while (nb > 0)
	{
		a = nb % 10;
		tabl[count] = a;
		count++;
		nb = nb / 10;
	}
	count--;
	while (count >= 0)
	{
		a = tabl[count];
		ft_putchar(a + '0');
		count--;
	}	
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else if (nb == 0)
		ft_putchar(48);
	else if (nb < 0)
	{
		nb = nb * -1;
		ft_putchar(45);
		ft_putnbr(nb);
	}
	else
		ft_putnbr2(nb);
}
